clc
close all
clear
I = 1;

ruta = strcat("SVA 11 CENTROIDE\", num2str(I), ".jpg");

f0 = imread(ruta);

f1 =  f0(:,:,3);
mesh(f1)