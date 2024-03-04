void main(List<String> args) {
  List<Map<String, dynamic>> etudiants = [
    {
      "nom": "D",
      'notes': [12, 20, 5]
    },
    {
      "nom": "B",
      'notes': [15, 18, 5]
    },
    {
      "nom": "C",
      'notes': [20, 20, 20]
    },
  ];
  etudiants.forEach((element) {
    num som = 0;
    List<num> notes = element['notes'];
    for (int i = 0; i < notes.length; i++) {
      som = som + notes[i];
    }
    num moy = som / notes.length;
    element['moy'] = moy;
    print('la moyen de ${element['nom']} est ${moy}');
  });
  tri(etudiants,'moy');
  etudiants.forEach((element) {
    print('${element['nom']}');
  });
}


List<Map<String, dynamic>> tri(List<Map<String, dynamic>> etudiants,
    [String champ = 'nom']) {
  // Tri des étudiants par le champ spécifié
  etudiants.sort((a, b) => a[champ].compareTo(b[champ]));
  return etudiants;
}
