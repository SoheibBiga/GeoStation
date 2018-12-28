class Grille {
public:
Grille(Joueur &, Joueur &);
void affiche() ; // Affiche la grille sur la sortie standard bool play(int, int, Joueur &);
bool aGagne(Case);
bool isOver(); // détecte la fin du jeu
private:
  Case board [3][3];
  Joueur & j1Croix;
  Joueur & j2Rond;
  Joueur joueurCurrent; // Le joueur qui a la main
  Case markCurrent; // la marque du joueur qui a la main
  friend ostream& operator<<(ostream& out, const Grille &);
};
