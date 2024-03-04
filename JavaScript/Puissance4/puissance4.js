window.onload = () => {

    const lignes = 7 ;
    const colonnes = 7;
    const plateau = Array.from(Array(colonnes), () => new Array(lignes).fill(''));
    const cases = document.querySelectorAll('.petit-carre');
    const reset = document.querySelector('.reset');
    const winner = document.querySelector('#winner');
    const affilies = document.querySelectorAll('.filled');
    let joueurCourant = "yellow";
  
    function puissance4() {
        let liIndex = parseInt(this.getAttribute('data-li'));
        let colIndex = parseInt(this.getAttribute('data-col'));

        if (liIndex + 1 < 5 ){
            if ( plateau[colIndex][liIndex + 1] == ''){
                while (liIndex + 1 < 6 && plateau[colIndex][liIndex + 1] == ''){
                    liIndex = liIndex + 1;
                }
                let caseCible = document.querySelector('[data-li="' + liIndex + '"][data-col="' + colIndex + '"]');
                caseCible.style.backgroundColor = joueurCourant;
                plateau[colIndex][liIndex] = joueurCourant;
                caseCible.removeEventListener('click',puissance4);
                caseCible.classList.add('filled');
            } else {
                plateau[colIndex][liIndex] = joueurCourant;
                this.style.backgroundColor = joueurCourant;
                this.removeEventListener('click',puissance4);
                this.classList.add('filled');
            }
        } else if (liIndex == 5) {
            plateau[colIndex][liIndex] = joueurCourant;
            this.style.backgroundColor = joueurCourant;
            this.removeEventListener('click',puissance4);
            this.classList.add('filled');
        }

        if(victoire(plateau, colIndex, liIndex)) {
            winner.innerHTML = joueurCourant + " a gagné" ;
            cases.forEach(cell => cell.removeEventListener('click',puissance4));
        } else if (affilies.length == 42) {
            winner.innerHTML = "Match nul !";
        }

        if (joueurCourant == "yellow"){
            joueurCourant = "red";
        }else{
            joueurCourant = "yellow" ;
        } 


    }
  
    function victoire(caseJoue, colIndex, liIndex) {
      //à gauche
      let win = 1;
      for (let i = 1; i <= 3; i++) {
        if (colIndex - i >= 0 && caseJoue[colIndex][liIndex] == caseJoue[colIndex - i][liIndex]) {
          win++;
        } else {
          break;
        }
      }
  
      //à droite
      win = 1;
      for (let i = 1; i <= 3; i++) {
        if (colIndex + i < 7 && caseJoue[colIndex][liIndex] == caseJoue[colIndex + i][liIndex]) {
          win++;
        } else {
          break;
        }
      }
  
      if (win === 4) {
        return true;
      }
  
      //en bas
      win = 1;
      for (let i = 1; i <= 3; i++) {
        if (liIndex + i < 6 && caseJoue[colIndex][liIndex] == caseJoue[colIndex][liIndex + i]) {
          win++;
        } else {
          break;
        }
      }
  
      if (win === 4) {
        return true;
      }
  
      //en haut
      win = 1;
      for (let i = 1; i <= 3; i++) {
        if (liIndex - i >= 0 && caseJoue[colIndex][liIndex] == caseJoue[colIndex][liIndex - i]) {
          win++;
        } else {
          break;
        }
      }
  
      if (win === 4) {
        return true;
      }
  
      //diagonale droite
      win = 1;
      for (let i = 1; i <= 3; i++) {
        if (liIndex + i < 6 && colIndex + i < 7 && caseJoue[colIndex][liIndex] == caseJoue[colIndex + i][liIndex + i]) {
          win++;
        } else {
          break;
        }
      }
  
      if (win === 4) {
        return true;
      }
  
      //diagonale gauche
      win = 1;
      for (let i = 1; i <= 3; i++) {
        if (liIndex + i < 6 && colIndex - i >= 0 && caseJoue[colIndex][liIndex] == caseJoue[colIndex - i][liIndex + i]) {
          win++;
        } else {
          break;
        }
      }
  
      if (win === 4) {
        return true;
      }
  
      return false;
    }
  
    function resetGame() {
      // Réinitialiser le jeu ici
        plateau.forEach(col => col.fill(''));
        cases.forEach( cell => {
            cell.style.backgroundColor = '';
            cell.addEventListener('click',puissance4);
            cell.classList.remove('filled');
            winner.innerHTML = '';
        });
       

    }
  
    reset.addEventListener('click', resetGame);
  
    cases.forEach((cell, index) => {
      const liIndex = Math.floor(index / lignes);
      const colIndex = index % colonnes;
      cell.setAttribute('data-li', liIndex);
      cell.setAttribute('data-col', colIndex);
      cell.addEventListener('click', puissance4);
    });
  
  }
  