%Clase 13/02/2025
%Imagenes procedurales

clc
close all
clear

for x=1:1:256
    for y=1:1:256
        f1(x,y)=127.5*sin(0.05*y)+127.5;
        f2(x,y)=127.5*(sin(0.05*x)+sin(0.05*y))/2+127.5;
        f3(x,y)=x;
        f4(x,y)=(x+y)/2;
        f5(x,y)=255*exp(-((x-127.5)^2+(y-127.5)^2)/100^2);
    end
end



IMA(:,:,1)=f5;
IMA(:,:,2)=f2;
IMA(:,:,3)=f4;

%figure,mesh(f5)
figure,imshow(uint8(IMA))


