clc 
clear
close all

% f0 = imread("I3.jpg");
f0 = imread("D3.jpg");

fR = f0(:,:,1);
fG = f0(:,:,2);
fB = f0(:,:,3);

% FBR = (fG<28 & fR>20);%Para izquierda
FBR = (fG<60 & fR>70);
FBC = (fR<80 & fB>90 & fG>90);
FPV = (fR<50 & fB<50);
FCA = (fR<40 & fB>70);

[filas, columnas] = size(fR);

x = 1:columnas;
y = 1:filas;

fxBR = sum(FBR,1);
fyBR = sum(FBR,2)';

fxBC = sum(FBC,1);
fyBC = sum(FBC,2)';

fxPV = sum(FPV,1);
fyPV = sum(FPV,2)';

fxCA = sum(FCA,1);
fyCA = sum(FCA,2)';

% figure, imshow(f2)
% figure, plot(fx)
% figure, plot(fy)

xcBR = round(sum(x.*fxBR)/sum(fxBR));
ycBR = round(sum(y.*fyBR)/sum(fyBR));

xcBC = round(sum(x.*fxBC)/sum(fxBC));
ycBC = round(sum(y.*fyBC)/sum(fyBC));

xcPV = round(sum(x.*fxPV)/sum(fxPV));
ycPV = round(sum(y.*fyPV)/sum(fyPV));

xcCA = round(sum(x.*fxCA)/sum(fxCA));
ycCA = round(sum(y.*fyCA)/sum(fyCA));
% 
XBA = xcBR;
YBA = ycBR;

XBC = xcBC;
YBC = ycBC;

XPV = xcPV;
YPV = ycPV;

XCA = xcCA;
YCA = ycCA;

% f0(ycBR,xcBR,:) = [255;255;255];
% f0(ycBC,xcBC,:) = [255;255;255];
% f0(ycPV,xcPV,:) = [255;255;255];
% f0(ycCA,xcCA,:) = [255;255;255];

for i=xcBR-5:xcBR+5
    for j=ycBR-5:ycBR+5
       f0(j,i,:) = [255;0;0]; 
    end
end
for i=xcBC-5:xcBC+5
    for j=ycBC-5:ycBC+5
       f0(j,i,:) = [0;255;255]; 
    end
end
for i=xcPV-5:xcPV+5
    for j=ycPV-5:ycPV+5
       f0(j,i,:) = [0;255;0]; 
    end
end
for i=xcCA-5:xcCA+5
    for j=ycCA-5:ycCA+5
       f0(j,i,:) = [100;100;255]; 
    end
end

figure,imshow(f0)
% figure,imshow(FBR)
% figure,imshow(FBC)
% figure,imshow(FPV)
figure,imshow(FCA)
