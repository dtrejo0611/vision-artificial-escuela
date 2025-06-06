clc
clear
close all

f0 = imread("0.bmp");
f1 = double(rgb2gray(f0));

[filas, columnas] = size(f1);

Sx = [-1 -2 -1; 0 0 0; 1 2 1];
Px = [-1 -1 -1; 0 0 0; 1 1 1];
Gx = [0 0 0; -1/2 0 1/2; 0 0 0];
Sy = Sx';
Py = Px';
Gy = Gx';


for i=2:filas-1
    for j=2:columnas-1
        V = f1(i-1:i+1,j-1:j+1);
        GSx(i,j) = sum(V.*Sx,'all');
        GSy(i,j) = sum(V.*Sy,'all');
        GS(i,j) = sqrt(GSx(i,j)^2+GSy(i,j)^2);
        GPx(i,j) = sum(V.*Px,'all');
        GPy(i,j) = sum(V.*Py,'all');
        GP(i,j) = sqrt(GPx(i,j)^2+GPy(i,j)^2);
        GGx(i,j) = sum(V.*Gx,'all');
        GGy(i,j) = sum(V.*Gy,'all');
        GG(i,j) = sqrt(GGx(i,j)^2+GGy(i,j)^2);
    end
end

% figure, imshow(uint8(GSx))
% figure, imshow(uint8(GSy))
figure, imshow(uint8(GS))
title('sobel')
figure, imshow(uint8(GP))
title('pevel')
figure, imshow(uint8(GG))
title('Gradiente')