clc;
clear;

% Crear el objeto de video desde la cámara predeterminada
cam = webcam(1);  % Si tienes más de una cámara, puedes usar webcam(2), etc.

% Crear figura
h = figure('Name', 'Video en Vivo', 'NumberTitle', 'off');
set(h, 'KeyPressFcn', @(~, event) assignin('base', 'key', event.Key));

key = '';  % Inicializar variable

while ishandle(h)
    % Capturar una imagen de la cámara
    frame = snapshot(cam);
    
    % Mostrar la imagen
    imshow(frame);
    title('Video en tiempo real...');
    if evalin('base', 'exist(''key'', ''var'')')
        key = evalin('base', 'key');
    end
    % Puedes ajustar este tiempo si necesitas menor carga de CPU
    pause(0.01);
end

% Liberar la cámara si la ventana se cierra
clear cam;
evalin('base', 'clear key');  % Limpiar variable de control