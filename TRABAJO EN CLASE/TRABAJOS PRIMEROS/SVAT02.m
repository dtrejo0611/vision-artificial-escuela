%SVAT02 Trejo David
%Cubo de colores en una sola imagen

clc
clear
close all

for x=1:765
    for y=1:1020
        if (x>255 && x<510) && (y<255)
            IMA(x,y,1)=0;
            IMA(x,y,2)=y;
            IMA(x,y,3)=255-(x-255);
        elseif (x>255 && x<510) && (y>255 && y<510)
            IMA(x,y,1)=(y-255);
            IMA(x,y,2)=255;
            IMA(x,y,3)=255-(x-255);
        elseif (x>255 && x<510) && (y>510 && y<765)
            IMA(x,y,1)=255;
            IMA(x,y,2)=255-(y-510);
            IMA(x,y,3)=255-(x-255);
        elseif (x>255 && x<510) && (y>765 && y<1020)
            IMA(x,y,1)=255-(y-765);
            IMA(x,y,2)=0;
            IMA(x,y,3)=255-(x-255);
        elseif (x<255) && (y>255 && y<510)
            IMA(x,y,1)=y-255;
            IMA(x,y,2)=x;
            IMA(x,y,3)=255;
        elseif (x>510 && x<765) && (y>255 && y<510)
            IMA(x,y,1)=(y-255);
            IMA(x,y,2)=255-(x-510);
            IMA(x,y,3)=0;
        else
            IMA(x,y,1)=0;
            IMA(x,y,2)=0;
            IMA(x,y,3)=0;
        end
    end
end

cubof = imrotate(IMA,270);

figure,imshow(uint8(cubof))
imwrite(uint8(cubof),"Cubof.bmp")