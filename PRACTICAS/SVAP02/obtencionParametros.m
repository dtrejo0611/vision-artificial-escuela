clc
close all
clear

I = 0;

ruta = strcat("C:\Users\dtrej\Documents\Semestre 25-2\VA\PRACTICAS" + ...
    "\SVAP02\fotos\VidOG100.png");
    
f0 = imread(ruta);

fR = f0(:,:,1);
fG = f0(:,:,2);
fB = f0(:,:,3);

FR = (fR<90);
FG = (fG<100);
FB = (fB<50);

[filas, columnas] = size(fR);

x = 1:columnas;
y = 1:filas;

fxC = sum(FR,1);
fyC = sum(FR,2)';

fxM = sum(FG,1);
fyM = sum(FG,2)';

fxY = sum(FB,1);
fyY = sum(FB,2)';

% figure, imshow(f2)
% figure, plot(fx)
% figure, plot(fy)

xcC = round(sum(x.*fxC)/sum(fxC));
ycC = round(sum(y.*fyC)/sum(fyC));

xcM = round(sum(x.*fxM)/sum(fxM));
ycM = round(sum(y.*fyM)/sum(fyM));

xcY = round(sum(x.*fxY)/sum(fxY));
ycY = round(sum(y.*fyY)/sum(fyY));
% 
XC = xcC;
YC = ycC;
XM = xcM;
YM = ycM;
XY = xcY;
YY = ycY;

f0(ycC,xcC,:) = [255;0;0];
f0(ycM,xcM,:) = [255;255;255];
f0(ycY,xcY,:) = [255;0;0];

for i=xcC-5:xcC+5
    for j=ycC-5:ycC+5
       f0(j,i,:) = [255;0;0]; 
    end
end

for i=xcM-5:xcM+5
    for j=ycM-5:ycM+5
       f0(j,i,:) = [255;0;0]; 
    end
end

for i=xcY-5:xcY+5
    for j=ycY-5:ycY+5
       f0(j,i,:) = [255;0;0]; 
    end
end

figure,imshow(f0)
figure,imshow(FR)
figure,imshow(FG)
figure,imshow(FB)
