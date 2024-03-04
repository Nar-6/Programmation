import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
        useMaterial3: true,
      ),
      debugShowCheckedModeBanner: false,
      home: const MyHomePage(title: 'Flutter Demo Home Page'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});
  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  int _counter = 0;

  void _incrementCounter() {
    setState(() {
      _counter = _counter + 1;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        body: Center(
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        crossAxisAlignment: CrossAxisAlignment.center,
        children: <Widget>[
          Padding(
            padding:
                EdgeInsets.all(8.0), // Espacement de tous les côtés du bouton
            child: ElevatedButton(
              onPressed: () {
                // Action à effectuer lors du clic sur le bouton 2
              },
              child: Text("Bouton 2"),
            ),
          ),
          Padding(
            padding:
                EdgeInsets.all(8.0), // Espacement de tous les côtés du bouton
            child: ElevatedButton(
              onPressed: () {
                // Action à effectuer lors du clic sur le bouton 2
              },
              child: Text("Bouton 2"),
            ),
          ),
          Padding(
            padding:
                EdgeInsets.all(8.0), // Espacement de tous les côtés du bouton
            child: ElevatedButton(
              onPressed: () {
                // Action à effectuer lors du clic sur le bouton 2
                Navigator.push(
                  context,
                  MaterialPageRoute(
                      builder: (context) =>
                          SecondScreen()), // Redirection vers SecondScreen
                );
              },
              child: Text("Bouton 2"),
            ),
          ),
        ],
      ),
    ));
  }
}

class SecondScreen extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('Deuxième écran')),
      body: Center(
        child: Text('Ceci est le deuxième écran'),
      ),
    );
  }
}
// import 'package:flutter/material.dart';

// void main() {
//   runApp(const MyApp());
// }

// class MyApp extends StatelessWidget {
//   const MyApp({super.key});
//   @override
//   Widget build(BuildContext context) {
//     return MaterialApp(
//       title: 'Convertisseur d\'Unités',
//       theme: ThemeData(
//         primarySwatch: Colors.red,
//       ),
//       home: const ConversionPage(),
//     );
//   }
// }

// class ConversionPage extends StatefulWidget {
//   const ConversionPage({super.key});

//   @override
//   // ignore: library_private_types_in_public_api
//   _ConversionPageState createState() => _ConversionPageState();
// }

// class _ConversionPageState extends State<ConversionPage> {
//   double inputValue = 0.0;
//   String selectedInputUnit = 'Mètre';
//   String selectedOutputUnit = 'Pied';
//   double outputValue = 0.0;
//   final List<String> lengthUnits = ['Mètre', 'Pied', 'Pouce'];
//   void convert() {
//     if (selectedInputUnit == 'Mètre' && selectedOutputUnit == 'Pied') {
//       outputValue = inputValue * 3.28084;
//     } else if (selectedInputUnit == 'Pied' && selectedOutputUnit == 'Mètre') {
//       outputValue = inputValue / 3.28084;
//     } else if (selectedInputUnit == 'Mètre' && selectedOutputUnit == 'Pouce') {
//       outputValue = inputValue * 39.3701;
//     } else if (selectedInputUnit == 'Pouce' && selectedOutputUnit == 'Mètre') {
//       outputValue = inputValue / 39.3701;
//     }
//     setState(() {});
//   }

//   @override
//   Widget build(BuildContext context) {
//     return Scaffold(
//       appBar: AppBar(
//         title: const Text('Convertisseur d\'Unités'),
//       ),
//       body: Padding(
//         padding: const EdgeInsets.all(16.0),
//         child: Column(
//           mainAxisAlignment: MainAxisAlignment.center,
//           children: [
//             TextField(
//               keyboardType: TextInputType.number,
//               decoration: const InputDecoration(labelText: 'Valeur'),
//               onChanged: (value) {
//                 inputValue = double.tryParse(value) ?? 0.0;
//               },
//             ),
//             const SizedBox(height: 20),
//             Row(
//               mainAxisAlignment: MainAxisAlignment.spaceEvenly,
//               children: [
//                 DropdownButton<String>(
//                   value: selectedInputUnit,
//                   onChanged: (String? newValue) {
//                     setState(() {
//                       selectedInputUnit = newValue!;
//                     });
//                   },
//                   items:
//                       lengthUnits.map<DropdownMenuItem<String>>((String value) {
//                     return DropdownMenuItem<String>(
//                       value: value,
//                       child: Text(value),
//                     );
//                   }).toList(),
//                 ),
//                 IconButton(
//                   icon: const Icon(Icons.swap_horiz),
//                   onPressed: () {
//                     setState(() {
//                       var temp = selectedInputUnit;
//                       selectedInputUnit = selectedOutputUnit;
//                       selectedOutputUnit = temp;
//                     });
//                   },
//                 ),
//                 DropdownButton<String>(
//                   value: selectedOutputUnit,
//                   onChanged: (String? newValue) {
//                     setState(() {
//                       selectedOutputUnit = newValue!;
//                     });
//                   },
//                   items:
//                       lengthUnits.map<DropdownMenuItem<String>>((String value) {
//                     return DropdownMenuItem<String>(
//                       value: value,
//                       child: Text(value),
//                     );
//                   }).toList(),
//                 ),
//               ],
//             ),
//             const SizedBox(height: 20),
//             ElevatedButton(
//               onPressed: () {
//                 convert();
//               },
//               child: const Text('Convertir'),
//             ),
//             const SizedBox(height: 20),
//             Text('Résultat : $outputValue $selectedOutputUnit'),
//           ],
//         ),
//       ),
//     );
//   }
// }
