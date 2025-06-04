clc
clear
close all

f0 = imread("0.bmp");

f1 = double(rgb2gray(f0));

imshow(uint8(f1))