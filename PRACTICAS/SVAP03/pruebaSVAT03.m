clc 
clear
close all

% i = 4;

% rutai = strcat("SVA12 VISION ESTEREO\Left Image ",num2str(i),".png");
% rutad = strcat("SVA12 VISION ESTEREO\Right Image ",num2str(i),".png");

% f0i = imread("I2.jpg");
% f0d = imread("D2.jpg");

imaqreset
% Inicializar la cámara
cam = videoinput('winvideo', 1); % Ajusta si usas otro formato
set(cam, 'ReturnedColorSpace', 'rgb');

% Mostrar vista previa
preview(cam);
disp('Vista previa iniciada...');

% Esperar a que presiones Enter
input('Presiona Enter para capturar la imagen...');

% Capturar la imagen
f0i = getsnapshot(cam);

% Detener vista previa
closepreview(cam);

imwrite(f0i, 'I5.jpg');

% Liberar la cámara
delete(cam);

imaqreset
% Inicializar la cámara
cam = videoinput('winvideo', 1); % Ajusta si usas otro formato
set(cam, 'ReturnedColorSpace', 'rgb');

% Mostrar vista previa
preview(cam);
disp('Vista previa iniciada...');

% Esperar a que presiones Enter
input('Presiona Enter para capturar la imagen...');

% Capturar la imagen
f0d = getsnapshot(cam);

% Detener vista previa
closepreview(cam);

imwrite(f0d, 'D5.jpg');

% Liberar la cámara
delete(cam);

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

FBRd = (fGd<60 & fRd>70);
FBVd = (fRd<100 & fBd<100 & fGd>80);
FBAd = (fBd<100 & fGd>100 & fRd>150);
FCAd = (fRd<50);

FBRi = (fGi<60 & fRi>70);
FBVi = (fRi<100 & fBi<100 & fGi>80);
FBAi = (fBi<100 & fGi>100 & fRi>150);
FCAi = (fRi<50);

[filas, columnas] = size(fRi);

x = 1:columnas;
y = 1:filas;

fxBRd = sum(FBRd,1);
fyBRd = sum(FBRd,2)';

fxBVd = sum(FBVd,1);
fyBVd = sum(FBVd,2)';

fxBAd = sum(FBAd,1);
fyBAd = sum(FBAd,2)';

fxCAd = sum(FCAd,1);
fyCAd = sum(FCAd,2)';

fxBRi = sum(FBRi,1);
fyBRi = sum(FBRi,2)';

fxBVi = sum(FBVi,1);
fyBVi = sum(FBVi,2)';

fxBAi = sum(FBAi,1);
fyBAi = sum(FBAi,2)';

fxCAi = sum(FCAi,1);
fyCAi = sum(FCAi,2)';

% figure, imshow(f2)
% figure, plot(fx)
% figure, plot(fy)

xcBRd = round(sum(x.*fxBRd)/sum(fxBRd));
ycBRd = round(sum(y.*fyBRd)/sum(fyBRd));

xcBVd = round(sum(x.*fxBVd)/sum(fxBVd));
ycBVd = round(sum(y.*fyBVd)/sum(fyBVd));

xcBAd = round(sum(x.*fxBAd)/sum(fxBAd));
ycBAd = round(sum(y.*fyBAd)/sum(fyBAd));

xcCAd = round(sum(x.*fxCAd)/sum(fxCAd));
ycCAd = round(sum(y.*fyCAd)/sum(fyCAd));
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
xcBRi = round(sum(x.*fxBRi)/sum(fxBRi));
ycBRi = round(sum(y.*fyBRi)/sum(fyBRi));

xcBVi = round(sum(x.*fxBVi)/sum(fxBVi));
ycBVi = round(sum(y.*fyBVi)/sum(fyBVi));

xcBAi = round(sum(x.*fxBAi)/sum(fxBAi));
ycBAi = round(sum(y.*fyBAi)/sum(fyBAi));

xcCAi = round(sum(x.*fxCAi)/sum(fxCAi));
ycCAi = round(sum(y.*fyCAi)/sum(fyCAi));

XBRi = xcBRi;
YBRi = ycBRi;

XBVi = xcBVi;
YBVi = ycBVi;

XBAi = xcBAi;
YBAi = ycBAi;

XCAi = xcCAi;
YCAi = ycCAi;

XBRd = xcBRd;
YBRd = ycBRd;

XBVd = xcBVd;
YBVd = ycBVd;

XBAd = xcBAd;
YBAd = ycBAd;

XCAd = xcCAd;
YCAd = ycCAd;

% [xi,yi,di] = impixel(f0i);

xcBRi = xcBRi-columnas/2;
ycBRi = filas/2-ycBRi;

xcBVi = xcBVi-columnas/2;
ycBVi = filas/2-ycBVi;

xcBAi = xcBAi-columnas/2;
ycBAi = filas/2-ycBAi;

xcCAi = xcCAi-columnas/2;
ycCAi = filas/2-ycCAi;

% [xd,yd,dd] = impixel(f0d);

xcBRd = xcBRd-columnas/2;
ycBRd = filas/2-ycBRd;

xcBVd = xcBVd-columnas/2;
ycBVd = filas/2-ycBVd;

xcBAd = xcBAd-columnas/2;
ycBAd = filas/2-ycBAd;

xcCAd = xcCAd-columnas/2;
ycCAd = filas/2-ycCAd;

d = 8.2;
% z = 49;%Backugan rojo


% f = z*(xi-xd)/d

%Promediar con varios experimentos con la ecuacion
f = 1130.57;
% 
zBR = (d*f)/(xcBRi-xcBRd)-2
zBV = (d*f)/(xcBVi-xcBVd)-2
zBA = (d*f)/(xcBAi-xcBAd)-2
zCA = (d*f)/(xcCAi-xcCAd)-2

for i=XBRi-5:XBRi+5
    for j=YBRi-5:YBRi+5
       f0i(j,i,:) = [255;0;0]; 
    end
end
for i=XBVi-5:XBVi+5
    for j=YBVi-5:YBVi+5
       f0i(j,i,:) = [0;255;0]; 
    end
end
for i=XBAi-5:XBAi+5
    for j=YBAi-5:YBAi+5
       f0i(j,i,:) = [255;255;0]; 
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
for i=XBVd-5:XBVd+5
    for j=YBVd-5:YBVd+5
       f0d(j,i,:) = [0;255;0]; 
    end
end
for i=XBAd-5:XBAd+5
    for j=YBAd-5:YBAd+5
       f0d(j,i,:) = [255;255;0]; 
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
baseline = 8.2; % distancia entre cámaras (d) en cm
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
xRbvd = (xcBVd*zBV)/f;
xRbad = (xcBAd*zBA)/f;
xRcad = (xcCAd*zCA)/f;

xRbri = (xcBRi*zBR)/f;
xRbvi = (xcBVi*zBV)/f;
xRbai = (xcBAi*zBA)/f;
xRcai = (xcCAi*zCA)/f;

xRBR = (xRbrd + xRbri)/2;
xRBV = (xRbvd + xRbvi)/2;
xRBA = (xRbad + xRbai)/2;
xRCA = (xRcad + xRcai)/2;

objetos = {
    xRBR, zBR, 'Bloque Rojo', 'r'
    xRBV, zBV, 'Bloque Verde', 'g'
    xRBA, zBA, 'Cubo rubick', 'y'
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



ylim([0, 50])