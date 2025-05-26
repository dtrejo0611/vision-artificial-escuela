% ----------------------------------------------
% SCRIPT MATLAB: Conversión de RGB a HSI
% ----------------------------------------------

% Cargar una imagen RGB
RGB = imread('0.bmp'); % Cambia 'mi_imagen.png' por tu imagen

% Convertir a double y normalizar si es necesario
if isa(RGB, 'uint8')
    RGB = double(RGB) / 255;
end

% Separar canales
R = RGB(:,:,1);
G = RGB(:,:,2);
B = RGB(:,:,3);

% -------------------------
% INTENSITY (I)
I = (R + G + B) / 3;

% -------------------------
% SATURATION (S)
min_RGB = min(min(R, G), B);
S = 1 - (3 ./ (R + G + B + eps)) .* min_RGB; % eps para evitar división por cero

% -------------------------
% HUE (H)
num = 0.5 * ( (R - G) + (R - B) );
den = sqrt( (R - G).^2 + (R - B).*(G - B) ) + eps; % eps para evitar división por cero
theta = acos(num ./ den);

H = theta; % Inicialmente igual a theta

% Ajuste si B > G
H(B > G) = 2*pi - H(B > G);

% Normalizar H a [0,1]
H = H / (2*pi);

% -------------------------
% Ensamblar la imagen HSI
HSI = cat(3, H, S, I);

% -------------------------
% Mostrar resultados

figure;

subplot(2,2,1);
imshow(RGB);
title('Imagen RGB');

subplot(2,2,2);
imshow(H);
title('Componente Hue');

subplot(2,2,3);
imshow(S);
title('Componente Saturación');

subplot(2,2,4);
imshow(I);
title('Componente Intensidad');

