clc 
clear
close all

% f0 = imread("I5.jpg");
f0 = imread("D5.jpg");

fR = f0(:,:,1);
fG = f0(:,:,2);
fB = f0(:,:,3);

% FBR = (fG<28 & fR>20);%Para izquierda
FBR = (fG<60 & fR>70);
FBV = (fR<100 & fB<100 & fG>80);
FBA = (fB<100 & fG>100 & fR>150);
FCA = (fR<50);

[filas, columnas] = size(fR);

x = 1:columnas;
y = 1:filas;

fxBR = sum(FBR,1);
fyBR = sum(FBR,2)';

fxBV = sum(FBV,1);
fyBV = sum(FBV,2)';

fxBA = sum(FBA,1);
fyBA = sum(FBA,2)';

fxCA = sum(FCA,1);
fyCA = sum(FCA,2)';

% figure, imshow(f2)
% figure, plot(fx)
% figure, plot(fy)

xcBR = round(sum(x.*fxBR)/sum(fxBR));
ycBR = round(sum(y.*fyBR)/sum(fyBR));

xcBV = round(sum(x.*fxBV)/sum(fxBV));
ycBV = round(sum(y.*fyBV)/sum(fyBV));

xcBA = round(sum(x.*fxBA)/sum(fxBA));
ycBA = round(sum(y.*fyBA)/sum(fyBA));

xcCA = round(sum(x.*fxCA)/sum(fxCA));
ycCA = round(sum(y.*fyCA)/sum(fyCA));
% 
XBR = xcBR;
YBR = ycBR;

XBV = xcBV;
YBV = ycBV;

XBA = xcBA;
YBA = ycBA;

XCA = xcCA;
YCA = ycCA;

f0(ycBR,xcBR,:) = [255;255;255];
f0(ycBV,xcBV,:) = [255;255;255];
f0(ycBA,xcBA,:) = [255;255;255];
f0(ycCA,xcCA,:) = [255;255;255];

for i=xcBR-5:xcBR+5
    for j=ycBR-5:ycBR+5
       f0(j,i,:) = [255;0;0]; 
    end
end
for i=xcBV-5:xcBV+5
    for j=ycBV-5:ycBV+5
       f0(j,i,:) = [0;255;0]; 
    end
end
for i=xcBA-5:xcBA+5
    for j=ycBA-5:ycBA+5
       f0(j,i,:) = [255;255;0]; 
    end
end
for i=xcCA-5:xcCA+5
    for j=ycCA-5:ycCA+5
       f0(j,i,:) = [100;100;255]; 
    end
end

figure,imshow(f0)
% figure,imshow(FBR)
figure,imshow(FBV)
% figure,imshow(FBA)
% figure,imshow(FCA)
