%20/02/2025
%Sistema CMY

clc
close all
clear

IMA=imread("0.bmp");

C=255-IMA(:,:,1);
M=255-IMA(:,:,2);
Y=255-IMA(:,:,3);

% figure,imshow(C)
% figure,imshow(M)
% figure,imshow(Y)
% 
% IMA2(:,:,1)=C;
% IMA2(:,:,2)=M;
% IMA2(:,:,3)=Y;

K=uint8(zeros(size(C)));
W=uint8(255*ones(size(C)));

IMA3(:,:,1)=C;
IMA3(:,:,2)=W;
IMA3(:,:,3)=W;

IMA4(:,:,1)=W;
IMA4(:,:,2)=M;
IMA4(:,:,3)=W;

IMA5(:,:,1)=W;
IMA5(:,:,2)=W;
IMA5(:,:,3)=Y;

figure,imshow(IMA3)
figure,imshow(IMA4)
figure,imshow(IMA5)