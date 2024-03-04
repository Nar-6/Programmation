window.onload = () => {
  const cases = document.querySelectorAll(".petit-carre");
  const tour = document.querySelector("#tour");
  const winner = document.querySelector("#winner");
  const reset = document.querySelector('.reset');
  let player = "X";


  tour.innerHTML = "C'est le tour de " + player;
  
      // function changeCouleur() {
    //     let min = 200;
    //     let max = 700;
    //     let randomInt = Math.floor(Math.random() * (max - min + 1) + min);
    //     let randomColor = "#" + randomInt.toString(16);
    //     this.style.backgroundColor = randomColor;
    // }


  function tictactoe() {
    if (this.innerHTML == '') {
      this.innerHTML = player;
      this.classList.add("filled"); // Ajoute la classe "filled" à la case remplie
      this.removeEventListener("click", tictactoe); // Désactive la case une fois qu'elle a été remplie

      if (player == "X") {
        player = "O";
      } else {
        player = "X";
      }

      // Vérifie s'il y a un gagnant ou s'il n'y a plus de cases disponibles
      const filledCases = document.querySelectorAll(".filled");
      const values = Array.from(filledCases).map((c) => c.innerHTML);
      const winningCombinations = [
        [0, 1, 2],
        [3, 4, 5],
        [6, 7, 8],
        [0, 3, 6],
        [1, 4, 7],
        [2, 5, 8],
        [0, 4, 8],
        [2, 4, 6],
      ];

      for (const combination of winningCombinations) {
        if (combination.every((i) => values[i] == "X")) {
          winner.innerHTML = "X a gagné !";
          return;
        }

        if (combination.every((i) => values[i] == "O")) {
          winner.innerHTML = "O a gagné !";
          return;
        }
      }

      if (filledCases.length == 9) {
        winner.innerHTML = "Match nul !";
      } else {

        tour.innerHTML = "C'est le tour de " + player; // Met à jour le texte indiquant le tour du joueur
      }

    }
  }

  function resetf() {

    for(let i=0; i<cases.length;i++){
      cases[i].innerHTML = '';
      cases[i].classList.remove("filled");
      cases[i].addEventListener("click",tictactoe);
    }
    winner.innerHTML = "";

  }
  reset.addEventListener("click",resetf);

  for (let i = 0; i < cases.length; i++) {
    cases[i].addEventListener("click", tictactoe);
  }

};
