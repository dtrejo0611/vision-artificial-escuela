function histo=obtencionHist(f0)
[filas, columnas] = size(f0);

histo=zeros(1,256);

for i=1:filas
    for j=1:columnas
        VR = f0(i,j);
        histo(VR+1) = histo(VR+1) + 1;
    end
end