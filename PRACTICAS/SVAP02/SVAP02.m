clc
close all
clear

XV=zeros(438,1);
YV=zeros(438,1);

XR=zeros(438,1);
YR=zeros(438,1);

XY=zeros(438,1);
YY=zeros(438,1);

TCV = zeros(438,2);
TCR = zeros(438,2);
TCY = zeros(438,2);

for I=1:438

    ruta = strcat("C:\Users\dtrej\Documents\Semestre 25-2\VA\PRACTICAS\" + ...
        "SVAP02\fotogramas\frame_",num2str(I-1),".jpg");

    ruta2 = strcat("C:\Users\dtrej\Documents\Semestre 25-2\VA" + ...
        "\PRACTICAS\SVAP02\resultado\res",num2str(I-1),".png");
    
    f0 = imread(ruta);
    f1 = f0;

    fR = f0(:,:,1);
    fG = f0(:,:,2);
    fB = f0(:,:,3);
    
    FR = (fR<50);
    FG = (fG<20 & fR>50);
    FB = (fB<100 & fG>20 & fR>50);
    
    [filas, columnas] = size(fR);
    
    x = 1:columnas;
    y = 1:filas;
    
    fxV = sum(FR,1);
    fyV = sum(FR,2)';

    xcV = round(sum(x.*fxV)/sum(fxV));
    ycV = round(sum(y.*fyV)/sum(fyV));

    XV(I) = xcV;
    YV(I) = ycV;
    
    fxR = sum(FG,1);
    fyR = sum(FG,2)';
        
    xcR = round(sum(x.*fxR)/sum(fxR));
    ycR = round(sum(y.*fyR)/sum(fyR));
    
    XR(I) = xcR;
    YR(I) = ycR;
        
    fxY = sum(FB,1);
    fyY = sum(FB,2)';

    xcY = round(sum(x.*fxY)/sum(fxY));
    ycY = round(sum(y.*fyY)/sum(fyY));

    XY(I) = xcY;
    YY(I) = ycY;

    TCV(I,:) = [XV(I), YV(I)];
    TCR(I,:) = [XR(I), YR(I)];
    TCY(I,:) = [XY(I), YY(I)];

    f1(ycV,xcV,:) = [255;0;0]; 
    f1(ycR,xcR,:) = [255;0;0]; 
    f1(ycY,xcY,:) = [255;0;0]; 

    % if I>2
    %     for k = 2:I
    %         f1 = insertShape(f1, 'Line', [TCV(k-1,1), TCV(k-1,2), ...
    %                                TCV(k,1), TCV(k,2)], ...
    %                     'Color', 'g', 'LineWidth', 2);
    %     end
    % 
    %     for k = 2:I
    %         f1 = insertShape(f1, 'Line', [TCR(k-1,1), TCR(k-1,2), ...
    %                                TCR(k,1), TCR(k,2)], ...
    %                     'Color', 'r', 'LineWidth', 2);
    %     end
    % 
    %     for k = 2:I
    %         f1 = insertShape(f1, 'Line', [TCY(k-1,1), TCY(k-1,2), ...
    %                                TCY(k,1), TCY(k,2)], ...
    %                     'Color', 'y', 'LineWidth', 2);
    %     end
    % 
    % 
    % end
    % 
    % imwrite(f1,ruta2)


end

figure;
subplot(3,1,1);
hold on
plot(XV, 'g')
plot(XR, 'r')
plot(XY, 'y')
hold off
title("Posicion X de los 3 objetos")
subplot(3,1,2);
hold on
plot(YV, 'g')
plot(YR, 'r')
plot(YY, 'y')
hold off
title("Posicion Y de los 3 objetos")
subplot(3,1,3);
hold on
plot(XV, YV, 'g')
plot(XR, YR, 'r')
plot(XY, YY, 'y')
hold off
title("Posicion general de los 3 objetos")
sgtitle('Posiciones de los 3 objetos')

figure, imshow(f0)
hold on;
plot(XV,YV, 'g', 'LineWidth', 3)
plot(XR,YR, 'r', 'LineWidth', 3)
plot(XY,YY, 'y', 'LineWidth', 3)
hold off;

VXV = zeros(437);
VYV = zeros(437);

for i=2:437
    VXV(i-1) = (XV(i)-XV(i-1))/(1/30);
    VYV(i-1) = (YV(i)-YV(i-1))/(1/30);
end

VXR = zeros(437);
VYR = zeros(437);

for i=2:437
    VXR(i-1) = (XR(i)-XR(i-1))/(1/30);
    VYR(i-1) = (YR(i)-YR(i-1))/(1/30);
end

VXY = zeros(437);
VYY = zeros(437);

for i=2:437
    VXY(i-1) = (XY(i)-XY(i-1))/(1/30);
    VYY(i-1) = (YY(i)-YY(i-1))/(1/30);
end

figure;
subplot(3,1,1);
hold on
plot(VXV, 'g')
plot(VXR, 'r')
plot(VXY, 'y')
hold off
title("Velocidad X de los 3 objetos")
subplot(3,1,2);
hold on
plot(VYV, 'g')
plot(VYR, 'r')
plot(VYY, 'y')
hold off
title("Velocidad Y de los 3 objetos")
subplot(3,1,3);
hold on
plot(VXV, VYV, 'g')
plot(VXR, VYR, 'r')
plot(VXY, VYY, 'y')
hold off
title("Velocidad general de los 3 objetos")
sgtitle('Velocidades de los 3 objetos')

AXV = zeros(436);
AYV = zeros(436);

for i=2:436
    AXV(i-1) = (VXV(i)-VXV(i-1))/(1/30);
    AYV(i-1) = (VYV(i)-VYV(i-1))/(1/30);
end

AXR = zeros(436);
AYR = zeros(436);

for i=2:436
    AXR(i-1) = (VXR(i)-VXR(i-1))/(1/30);
    AYR(i-1) = (VYR(i)-VYR(i-1))/(1/30);
end

AXY = zeros(436);
AYY = zeros(436);

for i=2:436
    AXY(i-1) = (VXY(i)-VXY(i-1))/(1/30);
    AYY(i-1) = (VYY(i)-VYY(i-1))/(1/30);
end

figure;
subplot(3,1,1);
hold on
plot(AXV, 'g')
plot(AXR, 'r')
plot(AXY, 'y')
hold off
title("Aceleracion X de los 3 objetos")
subplot(3,1,2);
hold on
plot(AYV, 'g')
plot(AYR, 'r')
plot(AYY, 'y')
hold off
title("Aceleracion Y de los 3 objetos")
subplot(3,1,3);
hold on
plot(AXV, AYV, 'g')
plot(AXR, AYR, 'r')
plot(AXY, AYY, 'y')
hold off
title("Aceleracion general de los 3 objetos")
sgtitle('Aceleraciones de los 3 objetos')

