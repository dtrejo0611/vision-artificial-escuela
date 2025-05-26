clc
clear
close all

N=5;
ruta = strcat("C:\Users\dtrej\Downloads\SVA 06 HISTOGRAMA-20250430T011009Z-001\SVA 06 HISTOGRAMA\",num2str(N),".jpg");
f = imread(ruta);
f0 = imcrop(f);

R = f0(:,:,1);
G = f0(:,:,2);
B = f0(:,:,3);

histoR=obtencionHist(R);
histoG=obtencionHist(G);
histoB=obtencionHist(B);

figure
hold on
plot(histoR, 'r')
plot(histoG, 'g')
plot(histoB, 'b')
hold off


