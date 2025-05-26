%26 FEB
%Sistema YIQ 

clc
close all
clear

IMA=imread("0.bmp");

% figure, imshow(IMA)

HSV=rgb2hsv(IMA);

H=HSV(:,:,1);
S=HSV(:,:,2);
V=HSV(:,:,3);

figure, imshow(H)
% figure, imshow(S)
% figure, imshow(V)


P(1,:,1)=[255*ones(1,256) 255:-1:0          zeros(1,256)    zeros(1,256)    0:1:255         255*ones(1,256)];
P(1,:,2)=[0:1:255         255*ones(1,256)   255*ones(1,256) 255:-1:0        zeros(1,256)    zeros(1,256)];
P(1,:,3)=[zeros(1,256)    zeros(1,256)      0:1:255         255*ones(1,256) 255*ones(1,256) 255:-1:0];

% imshow(uint8(P))

[filas, columnas]=size(H);

for i=1:filas
    for j=1:columnas
        H2(i,j,:)=P(1,uint32(1536*H(i,j)+1),:);
    end
end

figure, imshow(uint8(H2))

imwrite(H, 'MatrizHsincolor.bmp')
imwrite(H2, 'MatrizHconcolor.bmp')