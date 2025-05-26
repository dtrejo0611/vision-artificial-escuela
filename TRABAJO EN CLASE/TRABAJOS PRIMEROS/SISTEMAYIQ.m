%20/02/2025
%Sistema YIQ 

clc
close all
clear

IMA=imread("0.bmp");

R=IMA(:,:,1);
G=IMA(:,:,2);
B=IMA(:,:,3);

% figure,imshow(R)
% figure,imshow(G)
% figure,imshow(B)

Y=0.299*double(R)+0.587*double(G)+0.114*double(B);
I=0.595716*double(R)-0.274453*double(G)-0.32126*double(B);
Q=0.211456*double(R)-0.522591*double(G)+0.311135*double(B);

figure, imshow(uint8(Y))
figure, imshow(uint8(I))
figure, imshow(uint8(Q))


% V=rgb2gray(IMA);
% 
% figure, imshow(V)