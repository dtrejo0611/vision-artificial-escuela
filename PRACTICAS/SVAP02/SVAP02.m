clc
close all
clear

XC=zeros(295,1);
YC=zeros(295,1);

XM=zeros(295,1);
YM=zeros(295,1);

XY=zeros(295,1);
YY=zeros(295,1);

TCC = zeros(295,2);
TCM = zeros(295,2);
TCY = zeros(295,2);

for I=1:295

    ruta = strcat("C:\Users\dtrej\Documents\Semestre 25-2\VA\PRACTICAS\" + ...
        "SVAP02\og\",num2str(I),".png");

    ruta2 = strcat("C:\Users\dtrej\Documents\Semestre 25-2\VA" + ...
        "\PRACTICAS\SVAP02\resultado\res",num2str(I-1),".png");
    
    f0 = imread(ruta);
    f1 = f0;

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

    xcC = round(sum(x.*fxC)/sum(fxC));
    ycC = round(sum(y.*fyC)/sum(fyC));

    XC(I) = xcC;
    YC(I) = ycC;
    
    if I<177
        fxM = sum(FG,1);
        fyM = sum(FG,2)';
            
        xcM = round(sum(x.*fxM)/sum(fxM));
        ycM = round(sum(y.*fyM)/sum(fyM));
    
    end
    XM(I) = xcM;
    YM(I) = ycM;
        
    if I<186
        fxY = sum(FB,1);
        fyY = sum(FB,2)';
    
        xcY = round(sum(x.*fxY)/sum(fxY));
        ycY = round(sum(y.*fyY)/sum(fyY));
        
    end
    XY(I) = xcY;
    YY(I) = ycY;

    TCC(I,:) = [XC(I), YC(I)];
    TCM(I,:) = [XM(I), YM(I)];
    TCY(I,:) = [XY(I), YY(I)];

    f1(ycC,xcC,:) = [255;0;0]; 
    f1(ycM,xcM,:) = [255;0;0]; 
    f1(ycY,xcY,:) = [255;0;0]; 

    % if I>2
    %     for k = 2:I
    %         f1 = insertShape(f1, 'Line', [TCC(k-1,1), TCC(k-1,2), ...
    %                                TCC(k,1), TCC(k,2)], ...
    %                     'Color', 'c', 'LineWidth', 2);
    %     end
    % 
    %     for k = 2:I
    %         f1 = insertShape(f1, 'Line', [TCM(k-1,1), TCM(k-1,2), ...
    %                                TCM(k,1), TCM(k,2)], ...
    %                     'Color', 'm', 'LineWidth', 2);
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
plot(XC, 'c')
plot(XM, 'm')
plot(XY, 'y')
hold off
title("Posicion X de los 3 objetos")
subplot(3,1,2);
hold on
plot(YC, 'c')
plot(YM, 'm')
plot(YY, 'y')
hold off
title("Posicion Y de los 3 objetos")
subplot(3,1,3);
hold on
plot(XC, YC, 'c')
plot(XM, YM, 'm')
plot(XY, YY, 'y')
hold off
title("Posicion general de los 3 objetos")
sgtitle('Posiciones de los 3 objetos')

figure, imshow(f0)
hold on;
plot(XC,YC, 'c', 'LineWidth', 3)
plot(XM,YM, 'm', 'LineWidth', 3)
plot(XY,YY, 'y', 'LineWidth', 3)
hold off;

VXC = zeros(294);
VYC = zeros(294);

for i=2:294
    VXC(i-1) = (XC(i)-XC(i-1))/(1/30);
    VYC(i-1) = (YC(i)-YC(i-1))/(1/30);
end

VXM = zeros(294);
VYM = zeros(294);

for i=2:294
    VXM(i-1) = (XM(i)-XM(i-1))/(1/30);
    VYM(i-1) = (YM(i)-YM(i-1))/(1/30);
end

VXY = zeros(294);
VYY = zeros(294);

for i=2:294
    VXY(i-1) = (XY(i)-XY(i-1))/(1/30);
    VYY(i-1) = (YY(i)-YY(i-1))/(1/30);
end

figure;
subplot(3,1,1);
hold on
plot(VXC, 'c')
plot(VXM, 'm')
plot(VXY, 'y')
hold off
title("Velocidad X de los 3 objetos")
subplot(3,1,2);
hold on
plot(VYC, 'c')
plot(VYM, 'm')
plot(VYY, 'y')
hold off
title("Velocidad Y de los 3 objetos")
subplot(3,1,3);
hold on
plot(VXC, VYC, 'c')
plot(VXM, VYM, 'm')
plot(VXY, VYY, 'y')
hold off
title("Velocidad general de los 3 objetos")
sgtitle('Velocidades de los 3 objetos')

AXC = zeros(293);
AYC = zeros(293);

for i=2:293
    AXC(i-1) = (VXC(i)-VXC(i-1))/(1/30);
    AYC(i-1) = (VYC(i)-VYC(i-1))/(1/30);
end

AXM = zeros(293);
AYM = zeros(293);

for i=2:293
    AXM(i-1) = (VXM(i)-VXM(i-1))/(1/30);
    AYM(i-1) = (VYM(i)-VYM(i-1))/(1/30);
end

AXY = zeros(293);
AYY = zeros(293);

for i=2:293
    AXY(i-1) = (VXY(i)-VXY(i-1))/(1/30);
    AYY(i-1) = (VYY(i)-VYY(i-1))/(1/30);
end

figure;
subplot(3,1,1);
hold on
plot(AXC, 'c')
plot(AXM, 'm')
plot(AXY, 'y')
hold off
title("Aceleracion X de los 3 objetos")
subplot(3,1,2);
hold on
plot(AYC, 'c')
plot(AYM, 'm')
plot(AYY, 'y')
hold off
title("Aceleracion Y de los 3 objetos")
subplot(3,1,3);
hold on
plot(AXC, AYC, 'c')
plot(AXM, AYM, 'm')
plot(AXY, AYY, 'y')
hold off
title("Aceleracion general de los 3 objetos")
sgtitle('Aceleraciones de los 3 objetos')

