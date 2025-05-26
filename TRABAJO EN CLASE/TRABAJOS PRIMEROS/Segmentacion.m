%19/02/2025
%Segmentacion

clc
close all
clear

IMA=imread("0.bmp");

R=IMA(:,:,1);
G=IMA(:,:,2);
B=IMA(:,:,3);

figure,imshow(R)
figure,imshow(G)
figure,imshow(B)

% K=uint8(zeros(size(R)));
% W=uint8(255*ones(size(R)));
% 
% IMA2(:,:,1)=255-R;
% IMA2(:,:,2)=255-G;
% IMA2(:,:,3)=255-B;
% 
% figure,imshow(IMA2)