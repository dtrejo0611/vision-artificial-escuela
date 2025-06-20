clc
clear
close all

f0 = imread("0.bmp");
f1 = double(rgb2gray(f0));

[filas, columnas] = size(f1);
dx = 1;
Gx = zeros(size(f1));
Gy = zeros(size(f1));
G = zeros(size(f1));
for i=2:filas-1
    for j=2:columnas-1
        Gx(i,j)=(f1(i,j+dx)-f1(i,j-dx))/2*dx;
        Gy(i,j)=(f1(i+dx,j)-f1(i-dx,j))/2*dx;
        G(i,j)=sqrt(Gx(i,j)^2+Gy(i,j)^2);
    end
end

figure,imshow(uint8(255-Gx))
figure,imshow(uint8(255-Gy))
figure,imshow(uint8(255-G))

figure, mesh(atan2d(Gy,Gx))