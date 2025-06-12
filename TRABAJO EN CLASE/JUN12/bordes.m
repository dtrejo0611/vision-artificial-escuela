clc
clear
close all

n=1;

ruta = strcat("ELEMENTOS\", num2str(n), ".jpg");

f0 = imread(ruta);
imshow(f0)