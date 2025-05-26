%SVAP01

clc 
clear
close all


f0 = imread("0.bmp");

f1 = Escalamiento(1, 0.9, f0);
f2 = Canal('c', f1);
f3 = Correccion('c', f2);
histof2 = Histograma(f2);
histof3 = Histograma(f3);

figure, imshow(f0)
figure, imshow(f1)
figure, imshow(f2)
figure, imshow(f3)
figure, plot(histof2)
title('F2')
figure, plot(histof3)
title('F3')