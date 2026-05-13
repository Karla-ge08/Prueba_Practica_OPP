Algoritmo Sistema_Estudiantes
    
    Dimension listaEstudiantes[40]
    Dimension notas[5]
    
    // Carga de nombres
    listaEstudiantes[1] = "Acosta Hanna"
    listaEstudiantes[2] = "Andrade Hugo"
    listaEstudiantes[3] = "Atiencia Josué"
    listaEstudiantes[4] = "Balarrezo Diego"
    listaEstudiantes[5] = "Barrionuevo Job"
    listaEstudiantes[6] = "Bedoya Juan"
    listaEstudiantes[7] = "Bravo Samuel"
    listaEstudiantes[8] = "Cajiao Paulo"
    listaEstudiantes[9] = "Calvopiña Brandon"
    listaEstudiantes[10] = "Castelo Katherine"
    listaEstudiantes[11] = "Chacha Víctor"
    listaEstudiantes[12] = "Chiluiza Steed"
    listaEstudiantes[13] = "Domínguez Daniel"
    listaEstudiantes[14] = "Freire Alan"
    listaEstudiantes[15] = "Gualle Abisag"
    listaEstudiantes[16] = "Guaman Alexander"
    listaEstudiantes[17] = "Guanga Sebastian"
    listaEstudiantes[18] = "Guanotoa Karla"
    listaEstudiantes[19] = "Landeta Edison"
    listaEstudiantes[20] = "Lara Karen"
    listaEstudiantes[21] = "Loor Jhon"
    listaEstudiantes[22] = "Lopez Washington"
    listaEstudiantes[23] = "Miranda Imanol"
    listaEstudiantes[24] = "Monar Jhair"
    listaEstudiantes[25] = "Muyulema Mateo"
    listaEstudiantes[26] = "Narváez Antonella"
    listaEstudiantes[27] = "Nuñez Bryan"
    listaEstudiantes[28] = "Pilco Mario"
    listaEstudiantes[29] = "Pomaquero Katherine"
    listaEstudiantes[30] = "Quevedo Gina"
    listaEstudiantes[31] = "Rivadeneira Matias"
    listaEstudiantes[32] = "Rocha Carolina"
    listaEstudiantes[33] = "Sanchez Isaac"
    listaEstudiantes[34] = "Segovia Joseph"
    listaEstudiantes[35] = "Supe Joan"
    listaEstudiantes[36] = "Toapanta Matias"
    listaEstudiantes[37] = "Verdesoto Kevin"
    listaEstudiantes[38] = "Villacrés Alejandro"
    listaEstudiantes[39] = "Viteri Shantal"
    
    nomEstudiante = "Ninguno"
    opc = 0
    
    Repetir
        Escribir " "
        Escribir "======================================"
        Escribir "      SISTEMA INTERACTIVO PSINT       "
        Escribir "======================================"
        Escribir "Estudiante: ", nomEstudiante
        Escribir "1. Seleccionar Estudiante"
        Escribir "2. Operaciones Matematicas"
        Escribir "3. Registro de Notas (0-10)"
        Escribir "4. Salir"
        Escribir "Seleccione opcion: "
        Leer opc
        
        Segun opc Hacer
            1:
                Escribir "--- LISTA ---"
                Para i = 1 Hasta 39 Hacer
                    Escribir i, ". ", listaEstudiantes[i]
                FinPara
                Leer sel
                Si sel > 0 Y sel <= 39 Entonces
                    nomEstudiante = listaEstudiantes[sel]
                Sino
                    Escribir "Error"
                FinSi
            2:
                Escribir "1.Suma 2.Resta 3.Mult 4.Div"
                Leer m
                Escribir "Num 1: "
                Leer a
                Escribir "Num 2: "
                Leer b
                Segun m Hacer
                    1: res = a + b
                    2: res = a - b
                    3: res = a * b
                    4: 
                        Si b <> 0 Entonces
                            res = a / b
                        Sino
                            Escribir "Error Div/0"
                        FinSi
                FinSegun
                Escribir "Resultado: ", res
            3:
                SumaN = 0
                Para j = 1 Hasta 5 Hacer
                    Repetir
                        Escribir "Nota ", j, ":"
                        Leer n
                    Hasta Que n >= 0 Y n <= 10
                    SumaN = SumaN + n
                FinPara
                Prom = SumaN / 5
                Escribir "Promedio: ", Prom
            4:
                Escribir "Adios"
        FinSegun
    Hasta Que opc = 4
    
FinAlgoritmo