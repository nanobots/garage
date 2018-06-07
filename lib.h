    typedef struct{
        int idPropietario;
        char nombre[25];
        char domicilio[25];
        char nroTarjeta[25];
        char estado;
    }ePropietario;


    int buscoPropietario(ePropietario[], int, int);;
    /** \brief  intercala los datos cuando se ordenan
      *  \param  Estructura ePropietario
      *  \param  Tamaño de la estructura
      *  \return datos reubicados
    */
     void burbujeo(ePropietario[], int, int);

    /** \brief  Inicializa estructura ePropietario
     *  \param  Estructura ePropietario
     *  \return estructura inicializada (todos los estados en 0)
    */
    void inicializarEstadoPropietario(ePropietario[], int);

    /** \brief  Carga en la estructura datos para prueba
     *  \param  Estructura ePropietario
     *  \return estructura con datos cargados
    */
    void HardCodePropietario(ePropietario[],int i);

    /** \brief  ingreso de datos tipo char
      *  \param  char()
      *  \return dato ingresado
    */
    int  ingresoDatoInt(char[]);

    /** \brief  ingreso de datos tipo int
      *  \param  int
      *  \return dato ingresado
    */
    void *ingresoDatoChar(char[], char[]);

    /** \brief  buscar si hay lugar para agregar un registro
      *  \param  Estructura ePropietario
      *  \param  Tamaño de la estructura
     *  \return id del registro (posicion=1) o si esta lleno(posicion=-1)
    */
    int propietarioIdLibre(ePropietario[],int);

    int propietarioPosicionLibre(ePropietario[],int);

    /** \brief  buscar si hay lugar para agregar un registro
     *  \return id del registro (posicion=1) o si esta lleno(posicion=-1)
    */
    int propietarioExiste(ePropietario[],int, int);

    /** \brief  verifica si la estructura no contiene datos
      *  \param  Estructura ePropietario
      *  \param  Tamaño de la estructura
      *  \return estado de la estructura (0 vacio) o (1 si hay datos)
    */
    int ePropietarioVacio(ePropietario[], int);

    /** \brief  ordena estructura por ID
      *  \param  Estructura ePropietario
      *  \param  Tamaño de la estructura
      *  \return estructura ordenada
    */
    void ordenarPropietarioId(ePropietario[], int);

     /** \brief  ordena estructura por nombre
      *  \param  Estructura ePropietario
      *  \param  Tamaño de la estructura
      *  \return estructura ordenada
    */
    void ordenarPropietarioNombre(ePropietario[], int tampropietario);

     /** \brief  Lista los datos de la estructura
      *  \param  Estructura ePropietario
      *  \param  Tamaño de la estructura
      *  \return salida por pantalla
    */
    void mostrarListaPropietario(ePropietario[], int);

    /** \brief  ingreso de datos de opciones de menú
      *  \param  mensaje a mostrar
      *  \return dato ingresado
    */
     int  opcionesMenu(char[]);
