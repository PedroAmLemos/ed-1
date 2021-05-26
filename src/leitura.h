#ifndef __LEITURA__
#define __LEITURA__
    char *concatPathFile(char *path, char *fileName);
    void read(char *path, char *geo_name, char *qry_name, char *out_path, int ini_col, int cont_col, char *fina_col, int lisType, int fin_col, char* col_title);
    //recebe os nomes dos arquivos e caminhos da main (qry e geo)

#endif