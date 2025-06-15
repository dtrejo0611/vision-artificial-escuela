clc
clear
close all

firmas = [];
etiquetas = [];

% Cargar base de datos
formas = {'Circulo', 'Cuadrado', 'Rectangulo', 'Hexagono'};
for f = 1:length(formas)
    for i = 0:4
        datos = load(sprintf('BD/%s/%d.mat', formas{f}, i));
        firmas{end+1} = interp1(1:length(datos.dis), datos.dis, linspace(1,length(datos.dis),100));
        etiquetas{end+1} = formas{f};
    end
end

% Inicializar cámara
imaqreset
cam = videoinput('winvideo', 2);
set(cam, 'ReturnedColorSpace', 'rgb');
disp("Presiona una tecla para detener la ejecución")

hFig = figure;
while ishandle(hFig)
    % Captura de imagen
    frame = getsnapshot(cam);
    img_gray = imgaussfilt(rgb2gray(imresize(frame, 0.3)), 2);  % suavizado
    img_edge = edge(img_gray, 'canny', [0.1 0.9]);
    img_edge = bwmorph(img_edge, 'thin', 1);  % un solo paso de adelgazamiento

    % Detectar contornos cerrados
    B = bwboundaries(img_edge, 'noholes');

    if isempty(B)
        imshow(frame); title('No se detecta contorno');
        drawnow;
        continue;
    end

    % Usar el contorno más grande
    [~, idx] = max(cellfun(@length, B));
    contorno = B{idx};

    % Calcular centroide
    cx = round(mean(contorno(:,2)));
    cy = round(mean(contorno(:,1)));

    % Calcular firma radial
    dis = sqrt((contorno(:,2) - cx).^2 + (contorno(:,1) - cy).^2);
    dis = interp1(1:length(dis), dis, linspace(1, length(dis), 100));

    % Comparar con base de datos
    mejor_corr = -Inf;
    clase_detectada = "Desconocido";

    for k = 1:length(firmas)
        ref = firmas{k};
        cor = max(xcorr(dis - mean(dis), ref - mean(ref)));
        if cor > mejor_corr
            mejor_corr = cor;
            clase_detectada = etiquetas{k};
        end
    end

    % Mostrar resultado
    imshow(frame);
    title(['Detectado: ', clase_detectada]);
    drawnow;

    % Salir con tecla
    if waitforbuttonpress
        break;
    end
end

clear cam;
