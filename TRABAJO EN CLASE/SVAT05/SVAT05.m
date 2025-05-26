%20/02/2025
%SVAT05

clc
close all
clear

NEG1=imread("0.bmp");
NEG2=imread("5.bmp");
NEG3=imread("1.bmp");

C1=255-NEG1(:,:,1);
M1=255-NEG1(:,:,2);
Y1=255-NEG1(:,:,3);

C2=255-NEG2(:,:,1);
M2=255-NEG2(:,:,2);
Y2=255-NEG2(:,:,3);

C3=255-NEG3(:,:,1);
M3=255-NEG3(:,:,2);
Y3=255-NEG3(:,:,3);

IMA1(:,:,1)=C1;
IMA1(:,:,2)=M1;
IMA1(:,:,3)=Y1;

IMA2(:,:,1)=C2;
IMA2(:,:,2)=M2;
IMA2(:,:,3)=Y2;

IMA3(:,:,1)=C3;
IMA3(:,:,2)=M3;
IMA3(:,:,3)=Y3;

figure,imshow(IMA1)
figure,imshow(IMA2)
figure,imshow(IMA3)