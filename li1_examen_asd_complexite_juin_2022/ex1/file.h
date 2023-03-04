struct element{
    int cle;
    struct element *suivant;
};
struct file{
    struct element *tete;
    struct element *dernier;
};
struct file* creer_file();
unsigned file_vide(struct file *);
int premier(struct file *);
void enfiler(struct file *, int);
void defiler(struct file *);
