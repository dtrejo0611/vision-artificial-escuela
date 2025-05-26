function f1 = Escalamiento(metodo, n, f0)
%UNTITLED2 Summary of this function goes here
%Para seleccionar el metodo de escalamiento se debe seleccionar entre 1 
%para Muestreo simple, 2 para Promedio de vecindad o 3 para Mediana de 
%vecindad, cualquier otro caso regresara por metodo de muestreo simple


[filas, columnas, capas] = size(f0);
f1 = zeros(round(filas*n),round(columnas*n),capas);

switch metodo
    case 1 %Muestreo simple
        for i=1:filas
            for j=1:columnas
                xs = round(n*j);
                ys = round(n*i);
                if ys>0 && xs>0 && ys<=filas && xs<=columnas
                    f1(ys, xs, :) = f0(i, j, :);
                end
            end
        end
    case 2 %Promedio de vecindad
        bloque = round(1/n);
        for i=1:filas
            for j=1:columnas
                vecindad = f0((bloque*(i-1)+1):min(bloque*i, filas), (bloque*(j-1)+1):min(bloque*j, columnas),:);
                for c = 1:capas
                    f1(i,j,c) = mean(mean(vecindad(:,:,c)));
                end
            end
        end
    case 3 %Mediana de vecindad
        bloque = round(1/n);
        for i=1:filas
            for j=1:columnas
                vecindad = f0((bloque*(i-1)+1):min(bloque*i, filas), (bloque*(j-1)+1):min(bloque*j, columnas),:);
                for c = 1:capas
                    f1(i,j,c) = median(median(vecindad(:,:,c)));
                end
            end
        end
    otherwise %Muestreo simple
        for i=1:filas
            for j=1:columnas
                xs = round(n*j);
                ys = round(n*i);
                if ys>0 && xs>0 && ys<=filas && xs<=columnas
                    f1(ys, xs, :) = f0(i, j, :);
                end
            end
        end
end

f1 = uint8(f1);

end