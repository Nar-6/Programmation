window.onload = () => {
    const boardSize = 3; // Taille du plateau de jeu (3x3)
    const board = Array.from(Array(boardSize), () => new Array(boardSize).fill('')); // Tableau pour représenter le plateau de jeu
    const cases = document.querySelectorAll('.petit-carre');
    const tour = document.querySelector('#tour');
    const winner = document.querySelector('#winner');
    const reset = document.querySelector('.reset');
    let currentPlayer = 'X';
  
    tour.innerHTML = "C'est le tour de " + currentPlayer;
  
    function tictactoe() {
      const rowIndex = parseInt(this.getAttribute('data-row'));
      const colIndex = parseInt(this.getAttribute('data-col'));
  
      if (board[rowIndex][colIndex] === '') {
        board[rowIndex][colIndex] = currentPlayer;
        this.innerHTML = currentPlayer;
        this.classList.add('filled');
        this.removeEventListener('click', tictactoe);
  
        if (checkWin(currentPlayer)) {
          endGame(currentPlayer);
        } else if (isBoardFull()) {
          endGame(null);
        } else {
          changePlayer();
        }
      }
    }
  
    function checkWin(player) {
      // Vérification des lignes et colonnes
      for (let i = 0; i < boardSize; i++) {
        if (board[i].every((cell) => cell === player) || board.every((row) => row[i] === player)) {
          return true;
        }
      }
  
      // Vérification des diagonales
      if (board[0][0] === player && board[1][1] === player && board[2][2] === player) {
        return true;
      }
      if (board[0][2] === player && board[1][1] === player && board[2][0] === player) {
        return true;
      }
  
      return false;
    }
  
    function isBoardFull() {
      return board.every((row) => row.every((cell) => cell !== ''));
    }
  
    function changePlayer() {
      currentPlayer = currentPlayer === 'X' ? 'O' : 'X';
      tour.innerHTML = "C'est le tour de " + currentPlayer;
    }
  
    function endGame(winningPlayer) {
      if (winningPlayer) {
        winner.innerHTML = winningPlayer + ' a gagné !';
      } else {
        winner.innerHTML = 'Match nul !';
      }
  
      cases.forEach((cell) => cell.removeEventListener('click', tictactoe));
    }
  
    function resetGame() {
      board.forEach((row) => row.fill(''));
      cases.forEach((cell) => {
        cell.innerHTML = '';
        cell.classList.remove('filled');
        cell.addEventListener('click', tictactoe);
      });
      currentPlayer = 'X';
      tour.innerHTML = "C'est le tour de " + currentPlayer;
      winner.innerHTML = '';
    }
  
    reset.addEventListener('click', resetGame);
  
    cases.forEach((cell, index) => {
      const rowIndex = Math.floor(index / boardSize);
      const colIndex = index % boardSize;
      cell.setAttribute('data-row', rowIndex);
      cell.setAttribute('data-col', colIndex);
      cell.addEventListener('click', tictactoe);
    });
  };
  