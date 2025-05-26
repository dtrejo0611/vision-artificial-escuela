clc 
clear
close all

f0 = imread("0.bmp");

f1 = svaTransformaciones(f0, 0, 0, 0, 0.75);
imshow(f1)