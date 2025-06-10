clc 
clear
close all

i = 4;

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
f0i = getsnapshot(cam);

% Detener vista previa
closepreview(cam);

% Liberar la cámara
delete(cam);

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
f0d = getsnapshot(cam);

% Detener vista previa
closepreview(cam);

% Liberar la cámara
delete(cam);

[filas, columnas] = size(f0i);

f0i(filas/2,:)=zeros(1,columnas);
f0i(:,columnas/2)=zeros(filas,1);

f0d(filas/2,:)=zeros(1,columnas);
f0d(:,columnas/2)=zeros(filas,1);

[xi,yi,di] = impixel(f0i);

xi = xi-columnas/2;
yi = filas/2-yi;

[xd,yd,dd] = impixel(f0d);

xd = xd-columnas/2;
yd = filas/2-yd;

d = 10;
z = 50.2;


f = z*(xi-xd)/d

%Promediar con varios experimentos con la ecuacion
% f = 170.84;

% z = (d*f)/(xi-xd)