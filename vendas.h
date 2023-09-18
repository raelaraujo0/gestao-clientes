struct venda
{
    int id;
    float preco;
    int data;
    char categoria[30];
};

void registrar_venda(void);
void deletar_venda(void);
void atualizar_venda(void);
void ler_venda(void);