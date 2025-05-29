clc
close all
clear

X=zeros(7);
Y=zeros(7);

for I=1:7

    ruta = strcat("SVA 11 CENTROIDE\", num2str(I), ".jpg");
    
    f0 = imread(ruta);
    
    f1 =  f0(:,:,2);
    
    f2 = (f1<50);
    
    [filas, columnas] = size(f2);
    
    x = 1:columnas;
    y = 1:filas;
    
    fx = sum(f2,1);
    fy = sum(f2,2)';
    
    % figure, imshow(f2)
    % figure, plot(fx)
    % figure, plot(fy)
    
    xc = round(sum(x.*fx)/sum(fx));
    yc = round(sum(y.*fy)/sum(fy));
    
    X(I) = xc;
    Y(I) = yc;
    
    f0(yc,xc,:) = [255;255;255];
    
    % figure,imshow(f0)

end

figure, plot(X)
title("Posicion X")
figure, plot(Y)
title("Posicion Y")
figure, plot(X,Y)
title("Posicion")

VX = zeros(6);
VY = zeros(6);

for i=2:7
    VX(i-1) = X(i)-X(i-1);
    VY(i-1) = Y(i)-Y(i-1);
end

figure, plot(VX)
title("Velocidad X")
figure, plot(VY)
title("Velocidad Y")
figure, plot(VX,VY)
title("Velocidad")

AX = zeros(5);
AY = zeros(5);

for i=2:6
    AX(i-1) = VX(i)-VX(i-1);
    AY(i-1) = VY(i)-VY(i-1);
end

figure, plot(AX)
title("Aceleracion X")
figure, plot(AY)
title("Aceleracion Y")
figure, plot(AX,AY)
title("Aceleracion")