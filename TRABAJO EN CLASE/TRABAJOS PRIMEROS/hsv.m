% Leer imagen
img = imread('0.bmp');

% Convertir imagen de RGB a HSV
hsv_img = rgb2hsv(img);

% Separar los canales
H = hsv_img(:,:,1); % Matriz Hue
S = hsv_img(:,:,2); % Matriz Saturation
V = hsv_img(:,:,3); % Matriz Value

% Mostrar el canal H, por ejemplo
imshow(S, []);
title('Canal S');
