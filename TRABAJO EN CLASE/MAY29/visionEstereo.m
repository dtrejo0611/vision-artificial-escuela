clc 
clear
close all

i = 1;

rutai = strcat("E:\25-2\VA\TRABAJO EN CLASE\MAY29\SVA12 VISION ESTEREO\Left Image ",num2str(i),".png");
rutad = strcat("E:\25-2\VA\TRABAJO EN CLASE\MAY29\SVA12 VISION ESTEREO\Right Image ",num2str(i),".png");

f0i = imread(rutai);
f0d = imread(rutad);

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

d = 30;
% z = 40;


% f = z*(xi-xd)/d;

%Promediar con varios experimentos con la ecuacion
f = 170.84;

z = (d*f)/(xi-xd)