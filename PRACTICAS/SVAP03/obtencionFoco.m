clc 
clear
close all

i = 4;

f0d = imread('D5.jpg');
f0i = imread('I5.jpg');

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

d = 23.5;
z = 31;


f = z*(xi-xd)/d

%Promediar con varios experimentos con la ecuacion
% f = 1175;

% z = (d*f)/(xi-xd)