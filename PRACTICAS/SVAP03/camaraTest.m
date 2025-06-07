imaqreset
% Inicializar la cámara
cam = videoinput('winvideo', 1); % Ajusta si usas otro formato
set(cam, 'ReturnedColorSpace', 'rgb');

% Mostrar vista previa
preview(cam);
disp('Vista previa iniciada...');

% Esperar a que presiones Enter
input('Presiona Enter para capturar la imagen...');

% Capturar la imagen
img = getsnapshot(cam);

% Detener vista previa
closepreview(cam);

% Mostrar la imagen capturada
figure;
imshow(img);
title('Imagen capturada');

% (Opcional) Guardar la imagen
imwrite(img, 'captura.jpg');

% Liberar la cámara
delete(cam);
