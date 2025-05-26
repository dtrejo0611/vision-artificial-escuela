%Clase 12/02/2025
%Cubo de colores

clc
clear
close all

for x=1:256
    for y=1:256
        IMA1(x,y,1)=y;
        IMA1(x,y,2)=x;
        IMA1(x,y,3)=0;

        IMA2(x,y,1)=255-y;
        IMA2(x,y,2)=x;
        IMA2(x,y,3)=255;

        IMA3(x,y,1)=0;
        IMA3(x,y,2)=x;
        IMA3(x,y,3)=255-y;

        IMA4(x,y,1)=255;
        IMA4(x,y,2)=x;
        IMA4(x,y,3)=y;

        IMA5(x,y,1)=y;
        IMA5(x,y,2)=0;
        IMA5(x,y,3)=255-x;

        IMA6(x,y,1)=y;
        IMA6(x,y,2)=255;
        IMA6(x,y,3)=x;
    end
end

figure,imshow(uint8(IMA1))
figure,imshow(uint8(IMA2))
figure,imshow(uint8(IMA3))
figure,imshow(uint8(IMA4))
figure,imshow(uint8(IMA5))
figure,imshow(uint8(IMA6))
