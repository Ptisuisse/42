sigaction = 

int sigaction(int signum, const struct sigaction *act, struct sigaction *oldcat)

signum : le signal pour lequel on souhaite changer l action
act : pointeur vers struct de type sigaction qui va permettre
entres autres d indiquer une routine de gestion de signaux.
old : NULL (sauvegarer l ancien comportement)

l appel systeme sigaction() sert a modifier l action effectuee par 
un processus a la reception d un signal specifique

struct sigaction {
    void    *sa_handler; // (int)
    void    *sa_sigaction; // (int, siginfo_t *, void *)
    sigset_t    sa_mask; //
    int sa_flags; //
    void    *sa_restorer; //(void)
}

sa_handler : indique l action affectee au signal signum et 
peut etre SIG_DFL pour l action par defaut, SIG_IGN pour ignorer
le signal, ou un pointeur sur une fonction de gestion de signaux.

sa_mask : specifie un masque de signaux a bloquer pendant l execution
du gestionnaire. de plus le signal ayant appele le gestionnaire
est bloque a moins que l attribut SA_NODEFER soit precise

sa_flags : specifie un ensemble d attributs qui modifient le comportement
du signal. il est forme par un OU binaire '|' entre les options

siginfo_t : struc, gestionnaire de signal recevra 3 arguments
et non plus un signal. Dans ce cas, il faut utiliser le membre 
sa_sigaction au lieu de sa_handler. cet attribut n a pas de sens 
que lors de la mise en place d un gestionnaire de signal

https://www.codequoi.com/envoyer-et-intercepter-un-signal-en-c/
http://mat.free.free.fr/downloads/unix/signaux.pdf


int sigemptyset(sigset_t *set);
sigemptyset : met tous les bits de l’ensemble qu’on lui 
fournit à 0, ce qui indique qu’aucun signal n’est stocké dans 
l’ensemble. La fonction sigfillset fait le contraire en mettant 
tous les bits à 1, ce qui veut dire qu’elle ajoute tous les signaux
 à l’ensemble. Ces deux fonctions renvoient 0 en cas de succès ou 
 -1 en cas d’erreur.

int sigaddset(sigset_t *set, int signum);
La fonction sigaddset ajoute le signal signum à l’ensemble set 
tandis que sigdelset retire le signal signum de l’ensemble set. 
Ces deux fonctions renvoient aussi 0 en cas de succès ou -1 en cas
 d’erreur.
