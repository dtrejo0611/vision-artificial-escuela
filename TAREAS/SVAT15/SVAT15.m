clc
clear 
close all

f0 = imread("oCMYfB.jpg");

f0c = Correccion('c', f0);

f1 = imcrop(f0);

R = f1(:,:,1);
G = f1(:,:,2);
B = f1(:,:,3);

f2 = uint8(255*rgb2hsv(f1));

H = f2(:,:,1);
S = f2(:,:,2);
V = f2(:,:,3);

[PMR, PCR, PPR, FSR, FBR, histoR] = estadisticas(R);
[PMG, PCG, PPG, FSG, FBG, histoG] = estadisticas(G);
[PMB, PCB, PPB, FSB, FBB, histoB] = estadisticas(B);

[PMH, PCH, PPH, FSH, FBH, histoH] = estadisticas(H);
[PMS, PCS, PPS, FSS, FBS, histoS] = estadisticas(S);
[PMV, PCV, PPV, FSV, FBV, histoV] = estadisticas(V);

% figure, plot(histoR, "r")
% hold on
% plot(histoG, "g")
% plot(histoB, "b")
% hold off
% title('RGB')
% 
% figure, plot(histoH, "y")
% hold on
% plot(histoS, "c")
% plot(histoV, "k")
% hold off
% title('HSV')

f3 = uint8(zeros(size(f0)));
f7 = uint8(zeros(size(f0)));

[filas, columnas, capas] = size(f0);

for i=1:filas
    for j=1:columnas
        if f0(i,j,1) >= FSR && f0(i,j,1) <= FBR && f0(i,j,2) >= FSG...
                && f0(i,j,2) <= FBG && f0(i,j,3) >= FSB && f0(i,j,3) <= FBB
            f3(i,j,:) = f0(i,j,:);
        else
            f3(i,j,:) = [255;0;255];
        end
    end
end

for i=1:filas
    for j=1:columnas
        if f0(i,j,1) >= FSR && f0(i,j,1) <= FBR && f0(i,j,2) >= FSG...
                && f0(i,j,2) <= FBG && f0(i,j,3) >= FSB && f0(i,j,3) <= FBB
            f7(i,j,:) = [255;255;255];
        else
            f7(i,j,:) = [0;0;0];
        end
    end
end

figure, imshow(f3)
figure, imshow(f7)

%%%%%%%%%%%%%%%%%%%%%%%%%
f4 = uint8(zeros(size(f0)));
f5 = uint8(255*rgb2hsv(f0));
f6 = uint8(zeros(size(f0)));


[filas, columnas, capas] = size(f0);

for i=1:filas
    for j=1:columnas
        if f5(i,j,1) >= FSH && f5(i,j,1) <= FBH && f5(i,j,2) >= FSS...
                && f5(i,j,2) <= FBS && f5(i,j,3) >= FSV && f5(i,j,3) <= FBV
            f4(i,j,:) = f0(i,j,:);
        else
            f4(i,j,:) = [255;0;255];
        end
    end
end

for i=1:filas
    for j=1:columnas
        if f5(i,j,1) >= FSH && f5(i,j,1) <= FBH && f5(i,j,2) >= FSS...
                && f5(i,j,2) <= FBS && f5(i,j,3) >= FSV && f5(i,j,3) <= FBV
            f6(i,j,:) = [255;255;255];
        else
            f6(i,j,:) = [0;0;0];
        end
    end
end

figure, imshow(f4)
figure, imshow(f6)