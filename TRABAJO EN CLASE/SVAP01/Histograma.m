function histo=Histograma(f0)

[filas, columnas, capas] = size(f0);

if capas > 1
    f0 = rgb2gray(f0);
end

f0 = uint8(f0);

histo=zeros(1,256);

for i=1:filas
    for j=1:columnas
        VR = f0(i,j);
        histo(VR+1) = histo(VR+1) + 1;
    end
end