import sys, csv, os

""" --- CONSTANTES --- """
# Constantes numericas
INIT_INT = 0

# Codigos de verduras
TOMATE = "t"
LECHUGA = "l"
ZANAHORIA = "z"
BROCOLI = "b"
verduras = (TOMATE, LECHUGA, ZANAHORIA, BROCOLI)

# Posiciones de los lista_argumentos
POSICION_COMANDO = 1
ID_PEDIDO = 0
VERDURA = 1
CANTIDAD = 2 

# Comandos
LISTAR_PEDIDOS = "listar"
AGREGAR_PEDIDOS = "agregar"
ELIMINAR_PEDIDOS = "eliminar"
MODIFICAR_PEDIDOS = "modificar"
AYUDA = "ayuda"
comandos_validos = (LISTAR_PEDIDOS, AGREGAR_PEDIDOS, ELIMINAR_PEDIDOS, MODIFICAR_PEDIDOS, AYUDA)

# Listar pedidos
CANTIDAD_ARGUMENTOS_LISTAR_TODO = 2
CANTIDAD_ARGUMENTOS_LISTAR_ESPECIFICO = 3
POSICION_ID_NOMBRE_CLIENTE_LISTAR = 1
POSICION_ID_LISTAR = 2

# Agregar pedido
CANTIDAD_ARGUMENTOS_AGREGAR = 5
POSICION_CANTIDAD_AGREGAR = 2
POSICION_VERDURA_AGREGAR = 3
POSICION_CLIENTE_AGREGAR = 4
INCREMENTO_ID = 1

# Eliminar pedido
CANTIDAD_ARGUMENTOS_ELIMINAR = 3
POSICION_ID_ELIMINAR = 2

# Modificar pedido
CANTIDAD_ARGUMENTOS_MODIFICAR = 5
POSICION_ID_MODIFICAR = 2
POSICION_CANTIDAD_MODIFICAR = 3
POSICION_VERDURA_MODIFICAR = 4

# Ayuda
CANTIDAD_ARGUMENTOS_AYUDA_BASICA = 2
CANTIDAD_ARGUMENTOS_AYUDA_COMPLETO = 3
COMANDO_PARA_AYUDA = 2

# Archivos
ARCHIVO_PEDIDOS = "verduleria_enanitos.csv"
ARCHIVO_CLIENTES = "clientes.csv"
ARCHIVO_AUXILIAR_PEDIDOS = "auxiliarP.csv"
ARCHIVO_AUXILIAR_CLIENTES = "auxiliarC.csv"

# Modos de apertura de archivos
ESCRIBIR_ARCHIVO = "a"
REESCRIBIR_ARCHIVO = "w"
LEER_ARCHIVO = "r"
CREAR_ARCHIVO = "x"
LEER_ESCRIBIR_ARCHIVO = "r+"
""" --- CONSTANTES --- """

""" --- DICCIONARIOS --- """
# Lisa de comandos válidos con una breve descripción
diccionario_comandos_basico = {
    LISTAR_PEDIDOS: "para listar un pedido específico",
    AGREGAR_PEDIDOS: "para agregar un pedido",
    ELIMINAR_PEDIDOS: "para eliminar un pedido",
    MODIFICAR_PEDIDOS: "para modificar un pedido",
    AYUDA: "para mostrar los comandos válidos"
}

# Lista de comandos válidos con una descripción detallada, con sus argumentos
diccionario_comandos_completo = {
    LISTAR_PEDIDOS: "<id_pedido>, para listar un pedido específico (id_pedido = numero, sin los '<' y '>')",
    AGREGAR_PEDIDOS: f"<cantidad> <verdura> <cliente>, para agregar un pedido (cantidad = numero > 0, verdura = letra {verduras}," +
                        " cliente = nombre, sin los '<' y '>')",
    ELIMINAR_PEDIDOS: "<id_pedido>, para eliminar un pedido (id_pedido = numero, sin los '<' y '>')",
    MODIFICAR_PEDIDOS: f"<id_pedido> <verdura> <cantidad>, para modificar un pedido (id_pedido = numero, verdura = letra {verduras}," + 
                        " cantidad = numero > 0, sin los '<' y '>')",
    AYUDA: "<comando>, para mostrar información sobre un comando (comando = cualquier comando válido, sin los '<' y '>')"
}
""" --- DICCIONARIOS --- """

""" --- LISTADO DE PEDIDOS --- """
# Pre: -
# Post: Muestra un mensaje de error por consola
def error_no_existe_archivo():
    print(f"Ocurrió un error al buscar los archivos. Reintente.")
    print(f"Si no funciona, cree los archivos '{ARCHIVO_PEDIDOS}' y '{ARCHIVO_CLIENTES}'.")
    print(f"Para crear los archivos, creelos manualmente o agregue un pedido con el comando '{AGREGAR_PEDIDOS}'.")

# Pre: archivo es el nombre del archivo
# Post: Devuelve si el archivo existe o no, escribiendo un mensaje por consola
def existe_el_archivo(archivo):
    if not os.path.exists(archivo):
        print(f"El archivo {archivo} no existe.")
        return False
    return True

# Pre: verdura es el código de la verdura
# Post: devuelve por consola el nombre de la verdura
def escribir_verdura(verdura):
    if verdura == TOMATE:
        print("Producto: Tomate")
    elif verdura == LECHUGA:
        print("Producto: Lechuga")
    elif verdura == ZANAHORIA:
        print("Producto: Zanahoria")
    elif verdura == BROCOLI:
        print("Producto: Brócoli")

# Pre: pedido es un pedido en formato id;verdura;cantidad
# Post: muestra por consola el pedido
def escribir_pedido(pedido, nombre_cliente): #, nombre_cliente):
    print(f"Pedido número: {pedido[ID_PEDIDO]}")
    print(f"Producto: {pedido[VERDURA].upper()}")
    print(f"Cantidad: {pedido[CANTIDAD]}")
    print(f"Cliente: {nombre_cliente.capitalize() if nombre_cliente != '' else 'No se encontró el cliente'}")

# Pre: numero_pedido es el id del pedido y lectura_clientes es el archivo "clientes.csv" leído
# Post: devuelve el nombre del cliente que hizo el pedido, si no existe el pedido, devuelve un string vacío
def obtener_nombre_cliente(numero_pedido, lectura_clientes):
    for cliente in lectura_clientes:
        if cliente and cliente[ID_PEDIDO] == numero_pedido:
            return cliente[POSICION_ID_NOMBRE_CLIENTE_LISTAR]
    return ""

# Pre: el numero de pedido puede o no existir en el archivo "verduleria_enanitos.csv"
# Post: si el pedido existe, lo lista, si no existe, muestra un mensaje de error
def listar_pedido_especifico(numero_pedido):
    try:
        archivo_pedidos = open(ARCHIVO_PEDIDOS, LEER_ARCHIVO)
    except Exception as e:
        print(f"Ocurrió un error al abrir el archivo de pedidos: {e}")
        return

    try:
        archivo_clientes = open(ARCHIVO_CLIENTES, LEER_ARCHIVO)
    except Exception as e:
        print(f"Ocurrió un error al abrir el archivo de clientes: {e}")
        archivo_pedidos.close()
        return
    
    lectura_pedidos = csv.reader(archivo_pedidos, delimiter=';')
    lectura_clientes = csv.reader(archivo_clientes, delimiter=';')

    nombre_cliente = obtener_nombre_cliente(numero_pedido, lectura_clientes)

    if nombre_cliente:
        for pedido in lectura_pedidos:
            if pedido and pedido[ID_PEDIDO] == numero_pedido:
                print("-----------")
                escribir_pedido(pedido, nombre_cliente)
        print("-----------")
    else:
        print(f"No se encontró el pedido con el número {numero_pedido}.")

    archivo_pedidos.close()
    archivo_clientes.close()

# Pre: -
# Post: Lista todos los pedidos del archivo "verduleria_enanitos.csv", en caso de que no haya pedidos, 
#       muestra un mensaje de error
def listar_todos_los_pedidos():
    try:
        archivo_pedidos = open(ARCHIVO_PEDIDOS, LEER_ARCHIVO)
        lectura_pedidos = csv.reader(archivo_pedidos, delimiter=';')
    except Exception as e:
        print(f"Ocurrió un error al abrir el archivo de clientes: {e}.")
    try:
        archivo_clientes = open(ARCHIVO_CLIENTES, LEER_ARCHIVO)
        lectura_clientes = list(csv.reader(archivo_clientes, delimiter=';'))
    except Exception as e:
        print(f"Ocurrió un error al abrir el archivo de pedidos: {e}.")

    if lectura_pedidos and lectura_clientes:
        for pedido in lectura_pedidos:
            if pedido and len(pedido) > ID_PEDIDO:
                print("-----------")
                nombre_cliente = obtener_nombre_cliente(pedido[ID_PEDIDO], lectura_clientes)
                escribir_pedido(pedido, nombre_cliente)
        print("-----------")
    else:
        print("No hay pedidos.")

    archivo_clientes.close()
    archivo_pedidos.close()

# Pre: -
# Post: Lista todos los pedidos del archivo "verduleria_enanitos.csv", si 
def listar_pedidos(argumentos):
    if existe_el_archivo(ARCHIVO_PEDIDOS) and existe_el_archivo(ARCHIVO_CLIENTES):
        if len(argumentos) == CANTIDAD_ARGUMENTOS_LISTAR_TODO:
            listar_todos_los_pedidos()
        elif len(argumentos) == CANTIDAD_ARGUMENTOS_LISTAR_ESPECIFICO and argumentos[POSICION_ID_LISTAR].isdigit():
            listar_pedido_especifico(argumentos[POSICION_ID_LISTAR])
        else:
            print(f"Comando con argumentos no válidos, escriba '{AYUDA} {LISTAR_PEDIDOS}' para mas información sobre los argumentos.")
    else:
        error_no_existe_archivo()
"""--- LISTADO DE PEDIDOS ---"""

"""--- AGREGAR PEDIDO ---"""
# Pre: -
# Post: Chequea si el archivo pasado existe, si no existe, lo crea
def chequear_archivo(archivo):
    if not os.path.exists(archivo):
        try:
            open(archivo, CREAR_ARCHIVO)
        except Exception as e:
            print(f"Ocurrió un error al crear el archivo {archivo}: {e}.")
            return False
    return True

# Pre: -
# Post: Chequea si los archivos "verduleria_enanitos.csv" y "clientes.csv" existen, si no existen, los crea
def chequear_archivos():
    archivo_pedidos_creado = chequear_archivo(ARCHIVO_PEDIDOS)
    archivos_clientes_creado = chequear_archivo(ARCHIVO_CLIENTES) 
    
    if archivo_pedidos_creado and archivos_clientes_creado:
        return True
    return False

# Pre: verdura es el código de la verdura
# Post: devuelve si la verdura es válida (si está en la lista de verduras)
def verificar_verdura(verdura):
    return verdura.lower() in [TOMATE, LECHUGA, ZANAHORIA, BROCOLI]

# Pre: -
# Post: Devuelve si la longitud de los argumentos es válida
def longitud_argumentos_valida(argumentos):
    return len(argumentos) == CANTIDAD_ARGUMENTOS_AGREGAR

# Pre: -
# Post: Devuelve si la cantidad es un número
def cantidad_valida(cantidad):
    return cantidad.isdigit() and int(cantidad) > INIT_INT

# Pre: -
# Post: Devuelve si la verdura es un string
def verdura_valida(verdura):
    return verdura.isalpha() and verificar_verdura(verdura)

# Pre: -
# Post: Devuelve si los argumentos son validos para agregar un pedido
def condicion_agregar_pedido(argumentos):
    return (
        longitud_argumentos_valida(argumentos) and
        cantidad_valida(argumentos[POSICION_CANTIDAD_AGREGAR]) and
        verdura_valida(argumentos[POSICION_VERDURA_AGREGAR])
    )

# Pre: -
# Post: Devuelve elultimo id del archivo, el cual es el id mas grande
def get_ultimo_id(archivo):
    lectura_archivo = csv.reader(archivo, delimiter=';')

    ultimo_id = INIT_INT

    for fila in lectura_archivo:
        if fila and len(fila) > ID_PEDIDO:
            ultimo_id = max(ultimo_id, int(fila[ID_PEDIDO]))

    return ultimo_id

# Pre: archivo_pedidos y archivo_clientes son los archivos csv
# Post: Devuelve el id del pedido que se va a agregar (se busca el id mas grande entre los dos archivos y se le suma 1)
def get_nuevo_id(archivo_pedidos, archivo_clientes):
    ultimo_id_pedidos = get_ultimo_id(archivo_pedidos)
    ultimo_id_clientes = get_ultimo_id(archivo_clientes)

    return max(ultimo_id_pedidos, ultimo_id_clientes) + INCREMENTO_ID

# Pre: -
# Post: Agrega un pedido al archivo "verduleria_enanitos.csv" (id, verdura, cantidad)
# y al archivo "clientes.csv" (id, cliente)
def agregar_pedido(argumentos):
    if chequear_archivos():
        if condicion_agregar_pedido(argumentos):
            try:
                archivo_pedidos = open(ARCHIVO_PEDIDOS, LEER_ESCRIBIR_ARCHIVO, newline='\n')
            except Exception as e:
                print(f"Ocurrió un error al abrir el archivo de pedidos: {e}")
                return
            try:
                archivo_clientes = open(ARCHIVO_CLIENTES, LEER_ESCRIBIR_ARCHIVO, newline='\n')
            except Exception as e:
                print(f"Ocurrió un error al abrir el archivo de clientes: {e}")
                archivo_pedidos.close()
                return

            escritor_pedidos = csv.writer(archivo_pedidos, delimiter=';')
            escritor_clientes = csv.writer(archivo_clientes, delimiter=';')

            id_pedido_actual = get_nuevo_id(archivo_pedidos, archivo_clientes)

            pedido_nuevo_pedidos = [str(id_pedido_actual), argumentos[POSICION_VERDURA_AGREGAR].upper(), argumentos[POSICION_CANTIDAD_AGREGAR]]
            pedido_nuevo_clientes = [str(id_pedido_actual), argumentos[POSICION_CLIENTE_AGREGAR].capitalize()]

            escritor_pedidos.writerow(pedido_nuevo_pedidos)
            escritor_clientes.writerow(pedido_nuevo_clientes)

            archivo_pedidos.close()
            archivo_clientes.close()
            print(f"Pedido agregado, su número de pedido es {id_pedido_actual}")
        else:
            print(f"Comando con argumentos no válidos, escriba '{AYUDA} {AGREGAR_PEDIDOS}' para mas información sobre los argumentos")
    else:
        print("Ocurrió un error al abrir los archivos. Intente nuevamente.")
""" --- AGREGAR PEDIDO --- """

""" --- ELIMINAR PEDIDO --- """
# Pre: El archivo "archivo_original"
# Post: Devuelve si el pedido fue eliminado, además, elimina el pedido del archivo "archivo_original" 
def eliminar_pedido(id_pedido_a_eliminar, archivo_original, archivo_auxiliar):
    try:
        archivo_original_abierto = open(archivo_original, LEER_ARCHIVO, newline='')
    except Exception as e:
        print(f"Ocurrió un error al abrir el archivo de pedidos: {e}.")
        return False
    try:
        archivo_auxiliar_abierto = open(archivo_auxiliar, REESCRIBIR_ARCHIVO, newline='')
    except Exception as e:
        print(f"Ocurrió un error al abrir el archivo auxiliar de pedidos: {e}.")
        archivo_original_abierto.close()
        return False
    
    lectura_archivo_original = csv.reader(archivo_original_abierto, delimiter=';')
    escritura_archivo_auxiliar = csv.writer(archivo_auxiliar_abierto, delimiter=';') 

    pedido_eliminado = False
    for pedido in lectura_archivo_original:
        if pedido and pedido[ID_PEDIDO] != id_pedido_a_eliminar:
            escritura_archivo_auxiliar.writerow(pedido)
        else:
            pedido_eliminado = True

    archivo_original_abierto.close()
    archivo_auxiliar_abierto.close()
    os.remove(archivo_original)
    os.rename(archivo_auxiliar, archivo_original)

    return pedido_eliminado

# Pre: -
# Post: Elimina un pedido de ambos archivos ()"verduleria_enanitos.csv" y "clientes.csv") y muestra un mensaje por consola
def eliminar(argumentos):
    if existe_el_archivo(ARCHIVO_PEDIDOS) and existe_el_archivo(ARCHIVO_CLIENTES):
        if len(argumentos) == CANTIDAD_ARGUMENTOS_ELIMINAR:
            pedido_eliminado_pedidos = eliminar_pedido(argumentos[POSICION_ID_ELIMINAR], ARCHIVO_PEDIDOS, ARCHIVO_AUXILIAR_PEDIDOS)
            pedido_eliminado_clientes = eliminar_pedido(argumentos[POSICION_ID_ELIMINAR], ARCHIVO_CLIENTES, ARCHIVO_AUXILIAR_CLIENTES)

            if pedido_eliminado_pedidos and pedido_eliminado_clientes:
                print(f"Pedido '{argumentos[POSICION_ID_ELIMINAR]}' eliminado.")
            else:
                print(f"El pedido '{argumentos[POSICION_ID_ELIMINAR]}' no existe.")

        else:
            print(f"Comando con argumentos no válidos, escriba '{AYUDA} {ELIMINAR_PEDIDOS}' para mas información sobre los argumentos.")
    else:
        error_no_existe_archivo()
""" --- ELIMINAR PEDIDO --- """

"""--- MODIFICAR PEDIDO ---"""

# Pre: el archivo_original está abierto en modo lectura y el archivo_auxiliar está abierto en modo escritura
# Post: Modifica un pedido del archivo archivo_original (id, cantidad, verdura) y lo escribe en el archivo_auxiliar,
#       si el pedido no existe (no está esa verdura), lo agrega al final del archivo_auxiliar
def modificacion(archivo_original, archivo_auxiliar, argumentos):
    lectura_archivo_pedidos = csv.reader(archivo_original, delimiter=';')
    escritura_archivo_auxiliar = csv.writer(archivo_auxiliar, delimiter=';')

    id_modificar = argumentos[POSICION_ID_MODIFICAR]
    verdura_modificar = argumentos[POSICION_VERDURA_MODIFICAR].upper()
    cantidad_modificar = argumentos[POSICION_CANTIDAD_MODIFICAR]
    pedido_nuevo = [id_modificar, verdura_modificar, cantidad_modificar]    

    pedido_modificado = False
    id_existe = False
    pedido_anterior = []

    for pedido in lectura_archivo_pedidos:
        if id_modificar == pedido[ID_PEDIDO]:
            id_existe = True
            if pedido[VERDURA] == verdura_modificar.upper():
                pedido[CANTIDAD] = cantidad_modificar
                pedido_modificado = True
        else:
            if pedido_anterior and pedido_anterior[ID_PEDIDO] == id_modificar and not pedido_modificado:
                escritura_archivo_auxiliar.writerow(pedido_nuevo)
                pedido_modificado = True

        escritura_archivo_auxiliar.writerow(pedido)
        pedido_anterior = pedido

    if not pedido_modificado and id_existe:
        escritura_archivo_auxiliar.writerow(pedido_nuevo)

    return pedido_modificado

# Pre: -
# Post: Devuelve si los argumentos son válidos para modificar un pedido
def condicion_modificar(argumentos):
    return (
        len(argumentos) == CANTIDAD_ARGUMENTOS_MODIFICAR and
        cantidad_valida(argumentos[POSICION_CANTIDAD_MODIFICAR]) and
        verdura_valida(argumentos[POSICION_VERDURA_MODIFICAR])
    )

# Pre: -
# Post: Modifica un pedido del archivo "verduleria_enanitos.csv" (id, cantidad, verdura)
def modificar_pedidos(argumentos):
    try:
        archivo_pedidos = open(ARCHIVO_PEDIDOS, LEER_ARCHIVO, newline='')
    except Exception as e:
        print(f"Ocurrió un error al abrir el archivo de pedidos: {e}.")
        return False
    try:
        archivo_auxiliar = open(ARCHIVO_AUXILIAR_PEDIDOS, REESCRIBIR_ARCHIVO, newline='')
    except Exception as e:
        print(f"Ocurrió un error al abrir el archivo auxiliar de pedidos: {e}.")
        archivo_pedidos.close()
        return False
    
    pedido_modificado = modificacion(archivo_pedidos, archivo_auxiliar, argumentos)

    archivo_pedidos.close()
    archivo_auxiliar.close()

    os.remove(ARCHIVO_PEDIDOS)
    os.rename(ARCHIVO_AUXILIAR_PEDIDOS, ARCHIVO_PEDIDOS)

    return pedido_modificado

# Pre: -
# Post: Trata de modificar un pedido, si el pedido existe, lo modifica, si no existe, muestra un mensaje de error, 
#       si los argumentos no son válidos, muestra otro mensaje de error
def modificar(argumentos):
    if existe_el_archivo(ARCHIVO_PEDIDOS) and existe_el_archivo(ARCHIVO_CLIENTES):
        if condicion_modificar(argumentos):
            pedido_modificado_pedidos = modificar_pedidos(argumentos)
            if pedido_modificado_pedidos:
                print(f"Pedido '{argumentos[POSICION_ID_MODIFICAR]}' modificado.")
            else:
                print(f"El pedido '{argumentos[POSICION_ID_MODIFICAR]}' no existe.")
        else:
            print(f"Comando con argumentos no válidos, escriba '{AYUDA} {MODIFICAR_PEDIDOS}' para mas información sobre los argumentos.")
    else:
        error_no_existe_archivo()
"""--- MODIFICAR PEDIDO ---"""

""" --- AYUDA --- """
# Pre: -
# Post: Muestra por consola los comandos válidos
def ayuda_basica():
    print( "Comandos válidos:")
    for comando in comandos_validos:
        print( "     *", comando + ", " + diccionario_comandos_basico[comando] + ".")
    print(f"Si quieres mas información sobre un comando, o especificaciones de sus argumentos, escribe '{AYUDA}' <comando>.")

# Pre: -
# Post: Muestra por consola los comandos válidos para listar
def ayuda_listar():
    print(f"Comando '{LISTAR_PEDIDOS}' válido:")
    print( "     *", LISTAR_PEDIDOS + ", " + diccionario_comandos_basico[LISTAR_PEDIDOS], "(sin argumentos).")
    print( "     *", LISTAR_PEDIDOS, diccionario_comandos_completo[LISTAR_PEDIDOS] + ".")

# Pre: -
# Post: Muestra por consola los comandos válidos para agregar
def ayuda_agregar():
    print(f"Comando '{AGREGAR_PEDIDOS}' válido:")
    print( "     *", AGREGAR_PEDIDOS, diccionario_comandos_completo[AGREGAR_PEDIDOS] + ".")

# Pre: -
# Post: Muestra por consola los comandos válidos para eliminar
def ayuda_eliminar():
    print(f"Comando '{ELIMINAR_PEDIDOS}' válido:")
    print( "     *", ELIMINAR_PEDIDOS, diccionario_comandos_completo[ELIMINAR_PEDIDOS] + ".")

# Pre: -
# Post: Muestra por consola los comandos válidos para modificar
def ayuda_modificar():
    print(f"Comando '{MODIFICAR_PEDIDOS}' válido:")
    print( "     *", MODIFICAR_PEDIDOS, diccionario_comandos_completo[MODIFICAR_PEDIDOS] + ".")

# Pre: -
# Post: Muestra por consola los comandos válidos para ayuda
def ayuda_ayuda():
    print(f"Comando '{AYUDA}' válido:")
    print( "     *", AYUDA + ", " + diccionario_comandos_basico[AYUDA], "(sin argumentos).")
    print( "     *", AYUDA, diccionario_comandos_completo[AYUDA] + ".")

# Pre: -
# Post: Muestra por consola los comandos válidos
def ayuda(argumentos):
    if len(argumentos) == CANTIDAD_ARGUMENTOS_AYUDA_BASICA:
        ayuda_basica()
        return
    elif len(argumentos) == CANTIDAD_ARGUMENTOS_AYUDA_COMPLETO:
        comando = argumentos[COMANDO_PARA_AYUDA]
        if comando == LISTAR_PEDIDOS:
            ayuda_listar()
        elif comando == AGREGAR_PEDIDOS:
            ayuda_agregar()
        elif comando == ELIMINAR_PEDIDOS:
            ayuda_eliminar()
        elif comando == MODIFICAR_PEDIDOS:
            ayuda_modificar()
        elif comando == AYUDA:
            ayuda_ayuda()
        else:
            print(f"Comando con argumentos no válidos, escriba '{AYUDA} {AYUDA}' para mas información sobre los argumentos.")
    else:
        print(f"Comando con argumentos no válidos, escriba '{AYUDA} {AYUDA}' para mas información sobre los argumentos.")
""" --- AYUDA --- """

"""
Pre: -
Post: Dependiendo del comando ingresado por consola, se ejecuta la función correspondiente:
        listar, para listar todos los pedidos o un pedido específico
        agregar, para agregar un pedido 
        eliminar, para eliminar un pedido
        modificar, para modificar un pedido
        ayuda, para mostrar los comandos válidos
        En caso de que el comando no sea válido, muestra un mensaje de error
"""
def manejar_archivo(argumentos):

    if argumentos[POSICION_COMANDO] == LISTAR_PEDIDOS:
        listar_pedidos(argumentos)
    elif argumentos[POSICION_COMANDO] == AGREGAR_PEDIDOS:
        agregar_pedido(argumentos)
    elif argumentos[POSICION_COMANDO] == ELIMINAR_PEDIDOS:
        eliminar(argumentos)
    elif argumentos[POSICION_COMANDO] == MODIFICAR_PEDIDOS:
        modificar(argumentos)
    elif argumentos[POSICION_COMANDO] == AYUDA:
        ayuda(argumentos)

# Pre: -
# Post: Chequea si el comando ingresado por consola es válido, si no es válido, muestra un mensaje de error
def chequear_comando(argumentos = sys.argv):
    if argumentos[POSICION_COMANDO] not in comandos_validos:
        return False
    return True

if __name__ == "__main__":

    argumentos = sys.argv

    if chequear_comando(argumentos):
        manejar_archivo(argumentos)
    else:
        print(f"Comando no válido, escriba '{AYUDA}' para mas información.")
