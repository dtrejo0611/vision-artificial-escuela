clc 
clear
close all

for i=1:25
    ruta = strcat('MODELOS HU\', num2str(i), '.bmp');
    f0 = imread(ruta);
    f1 = rgb2gray(f0);
    f2 = double(f1<200);
    f3 = uint8(255*f2);
    subplot(5,5,i),imshow(f3)
    m00 = MomentoInicial(f2,0,0);
    m01 = MomentoInicial(f2,0,1);
    m10 = MomentoInicial(f2,1,0);
    
    xc = m10/m00;
    yc = m01/m00;
    
    u00 = MomentoCentral(f2,0,0,xc,yc);
    u20 = MomentoCentral(f2,2,0,xc,yc);
    u02 = MomentoCentral(f2,0,2,xc,yc);
    
    n20 = MomentoNormalizado(u20,u00,2,0);
    n02 = MomentoNormalizado(u02,u00,0,2);
    
    phi1 = n20+n02;
    title(strcat("phi = ",num2str(phi1)))
end