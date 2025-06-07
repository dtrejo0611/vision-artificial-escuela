clc 
clear
close all

i = 4;

% rutai = strcat("SVA12 VISION ESTEREO\Left Image ",num2str(i),".png");
% rutad = strcat("SVA12 VISION ESTEREO\Right Image ",num2str(i),".png");

f0i = imread("I2.jpg");
f0d = imread("D2.jpg");

% [filas, columnas] = size(f0i);
% 
% f0i(round(filas/2),:)=zeros(1,columnas);
% f0i(:,round(columnas/2))=zeros(filas,1);
% 
% f0d(round(filas/2),:)=zeros(1,columnas);
% f0d(:,round(columnas/2))=zeros(filas,1);

fRd = f0d(:,:,1);
fGd = f0d(:,:,2);
fBd = f0d(:,:,3);

fRi = f0i(:,:,1);
fGi = f0i(:,:,2);
fBi = f0i(:,:,3);

% FBR = (fG<28 & fR>20);%Para izquierda
FBRd = (fGd<60 & fRd>70);
FBCd = (fRd<50 & fGd>30 & fBd>70);
FPVd = (fGd<50 & fBd<25 & fRd<20);
FCAd = (fGd<40 & fBd>35 & fRd<40);

FBRi = (fGi<60 & fRi>70);
FBCi = (fRi<50 & fGi>30 & fBi>70);
FPVi = (fGi<50 & fBi<25 & fRi<20);
FCAi = (fGi<40 & fBi>35 & fRi<40);

[filas, columnas] = size(fRi);

x = 1:columnas;
y = 1:filas;

fxBRd = sum(FBRd,1);
fyBRd = sum(FBRd,2)';

fxBCd = sum(FBCd,1);
fyBCd = sum(FBCd,2)';

fxPVd = sum(FPVd,1);
fyPVd = sum(FPVd,2)';

fxCAd = sum(FCAd,1);
fyCAd = sum(FCAd,2)';

fxBRi = sum(FBRi,1);
fyBRi = sum(FBRi,2)';

fxBCi = sum(FBCi,1);
fyBCi = sum(FBCi,2)';

fxPVi = sum(FPVi,1);
fyPVi = sum(FPVi,2)';

fxCAi = sum(FCAi,1);
fyCAi = sum(FCAi,2)';

% figure, imshow(f2)
% figure, plot(fx)
% figure, plot(fy)

xcBRd = round(sum(x.*fxBRd)/sum(fxBRd));
ycBRd = round(sum(y.*fyBRd)/sum(fyBRd));

xcBCd = round(sum(x.*fxBCd)/sum(fxBCd)-25);
ycBCd = round(sum(y.*fyBCd)/sum(fyBCd));

xcPVd = round(sum(x.*fxPVd)/sum(fxPVd));
ycPVd = round(sum(y.*fyPVd)/sum(fyPVd));

xcCAd = round(sum(x.*fxCAd)/sum(fxCAd));
ycCAd = round(sum(y.*fyCAd)/sum(fyCAd));
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
xcBRi = round(sum(x.*fxBRi)/sum(fxBRi));
ycBRi = round(sum(y.*fyBRi)/sum(fyBRi));

xcBCi = round(sum(x.*fxBCi)/sum(fxBCi));
ycBCi = round(sum(y.*fyBCi)/sum(fyBCi));

xcPVi = round(sum(x.*fxPVi)/sum(fxPVi)+70);
ycPVi = round(sum(y.*fyPVi)/sum(fyPVi));

xcCAi = round(sum(x.*fxCAi)/sum(fxCAi));
ycCAi = round(sum(y.*fyCAi)/sum(fyCAi));

XBRi = xcBRi;
YBRi = ycBRi;

XBCi = xcBCi;
YBCi = ycBCi;

XPVi = xcPVi;
YPVi = ycPVi;

XCAi = xcCAi;
YCAi = ycCAi;

XBRd = xcBRd;
YBRd = ycBRd;

XBCd = xcBCd;
YBCd = ycBCd;

XPVd = xcPVd;
YPVd = ycPVd;

XCAd = xcCAd;
YCAd = ycCAd;

% [xi,yi,di] = impixel(f0i);

xcBRi = xcBRi-columnas/2;
ycBRi = filas/2-ycBRi;

xcBCi = xcBCi-columnas/2;
ycBCi = filas/2-ycBCi;

xcPVi = xcPVi-columnas/2;
ycPVi = filas/2-ycPVi;

xcCAi = xcCAi-columnas/2;
ycCAi = filas/2-ycCAi;

% [xd,yd,dd] = impixel(f0d);

xcBRd = xcBRd-columnas/2;
ycBRd = filas/2-ycBRd;

xcBCd = xcBCd-columnas/2;
ycBCd = filas/2-ycBCd;

xcPVd = xcPVd-columnas/2;
ycPVd = filas/2-ycPVd;

xcCAd = xcCAd-columnas/2;
ycCAd = filas/2-ycCAd;

d = 10;
% z = 49;%Backugan rojo


% f = z*(xi-xd)/d

%Promediar con varios experimentos con la ecuacion
f = 1.5778e+03;
% 
zBR = (d*f)/(xcBRi-xcBRd)
zBC = (d*f)/(xcBCi-xcBCd)
zPV = (d*f)/(xcPVi-xcPVd)
zCA = (d*f)/(xcCAi-xcCAd)

for i=XBRi-5:XBRi+5
    for j=YBRi-5:YBRi+5
       f0i(j,i,:) = [255;0;0]; 
    end
end
for i=XBCi-5:XBCi+5
    for j=YBCi-5:YBCi+5
       f0i(j,i,:) = [0;255;255]; 
    end
end
for i=XPVi-5:XPVi+5
    for j=YPVi-5:YPVi+5
       f0i(j,i,:) = [0;255;0]; 
    end
end
for i=XCAi-5:XCAi+5
    for j=YCAi-5:YCAi+5
       f0i(j,i,:) = [100;100;255]; 
    end
end

for i=XBRd-5:XBRd+5
    for j=YBRd-5:YBRd+5
       f0d(j,i,:) = [255;0;0]; 
    end
end
for i=XBCd-5:XBCd+5
    for j=YBCd-5:YBCd+5
       f0d(j,i,:) = [0;255;255]; 
    end
end
for i=XPVd-5:XPVd+5
    for j=YPVd-5:YPVd+5
       f0d(j,i,:) = [0;255;0]; 
    end
end
for i=XCAd-5:XCAd+5
    for j=YCAd-5:YCAd+5
       f0d(j,i,:) = [100;100;255]; 
    end
end

figure,imshow(f0i)
figure,imshow(f0d)

figure
hold on
axis equal
grid on
xlabel('X (cm)')
ylabel('Z (cm)')
title('Vista en planta (X-Z) del entorno y cámaras')

% Parámetros de la escena
baseline = 10; % distancia entre cámaras (d) en cm
fov = 60; % campo de visión en grados (30° hacia cada lado)
cam_z = 0; % Las cámaras están en z = 0

% Dibujar cámaras (posición X, Z)
plot(-baseline/2, cam_z, 'ks', 'MarkerSize', 10, 'MarkerFaceColor', 'k') % Cámara izquierda
plot( baseline/2, cam_z, 'ks', 'MarkerSize', 10, 'MarkerFaceColor', 'k') % Cámara derecha
text(-baseline/2 - 1, -2, 'Cam Izq')
text( baseline/2 + 0.5, -2, 'Cam Der')

% Dibujar ángulos de visión
max_view = 100; % distancia máxima para dibujar las líneas de visión

% Líneas de visión cámara izquierda
line([-baseline/2, -baseline/2 + max_view*tand(-fov/2)], [0, max_view], 'Color', [0.5 0.5 0.5], 'LineStyle', '--')
line([-baseline/2, -baseline/2 + max_view*tand(fov/2)], [0, max_view], 'Color', [0.5 0.5 0.5], 'LineStyle', '--')

% Líneas de visión cámara derecha
line([baseline/2, baseline/2 + max_view*tand(-fov/2)], [0, max_view], 'Color', [0.5 0.5 0.5], 'LineStyle', '--')
line([baseline/2, baseline/2 + max_view*tand(fov/2)], [0, max_view], 'Color', [0.5 0.5 0.5], 'LineStyle', '--')

xRbrd = (xcBRd*zBR)/f;
xRbcd = (xcBCd*zBC)/f;
xRpvd = (xcPVd*zPV)/f;
xRcad = (xcCAd*zCA)/f;

xRbri = (xcBRi*zBR)/f;
xRbci = (xcBCi*zBC)/f;
xRpvi = (xcPVi*zPV)/f;
xRcai = (xcCAi*zCA)/f;

xRBR = (xRbrd + xRbri)/2;
xRBC = (xRbcd + xRbci)/2;
xRPV = (xRpvd + xRpvi)/2;
xRCA = (xRcad + xRcai)/2;

objetos = {
    xRBR, zBR, 'Rojo', 'r'
    xRBC, zBC, 'Cian', 'c'
    xRPV, zPV, 'Verde', 'g'
    xRCA, zCA, 'Carro Azul', 'b'
};

% Dibujar los objetos en el plano
for k = 1:size(objetos,1)
    x = objetos{k,1};
    z = objetos{k,2};
    nombre = objetos{k,3};
    color = objetos{k,4};

    plot(x, z, 'o', 'MarkerSize', 10, 'MarkerFaceColor', color, 'MarkerEdgeColor', 'k')
    text(x + 1, z + 2, nombre, 'FontSize', 9)
end



ylim([0, 100])