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



ylim([0, 100])