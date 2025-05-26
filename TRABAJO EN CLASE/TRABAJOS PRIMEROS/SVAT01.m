%SVAT01
%Patron procedural

clc
close all
clear
for x=1:1:720
    for y=1:1:1080
        f1(x,y)=-(127.5*(tan(0.05*x)+tan(0.05*y))/2+127.5);
        f2(x,y)=127.5*(tan(0.05*x)+tan(0.05*y))/2+127.5;
        f3(x,y)=127.5*(tan(0.05*x)-tan(0.05*y))/2+127.5;
    end
end

IMA(:,:,1)=f1;
IMA(:,:,2)=f2;
IMA(:,:,3)=f3;
%figure,mesh(f5)
patronf = imrotate(IMA,90);
figure,imshow(uint8(patronf))
imwrite(uint8(patronf),"PATRONF.bmp")