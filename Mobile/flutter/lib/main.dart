import 'package:flutter/material.dart';
void main() {
runApp(const MyApp());
}
  class MyApp extends StatelessWidget {
  const MyApp({super.key});
  @override
  Widget build(BuildContext context) {
  return MaterialApp(
  title: 'Convertisseur d\'Unités',
  theme: ThemeData(
  primarySwatch: Colors.orange,
  ),
  home: const ConversionPage(),);
 }
}
class ConversionPage extends StatefulWidget {
  const ConversionPage({super.key});

@override
 // ignore: library_private_types_in_public_api
 _ConversionPageState createState() => _ConversionPageState();
}
class _ConversionPageState extends State<ConversionPage> {
    double inputValue = 0.0;
    String selectedInputUnit = 'Mètre';
    String selectedOutputUnit = 'Pied';
    double outputValue = 0.0;
    final List<String> lengthUnits = ['Mètre', 'Pied', 'Pouce'];
    void convert() {
    if (selectedInputUnit == 'Mètre' && selectedOutputUnit == 'Pied') {
    outputValue = inputValue * 3.28084;
    } else if (selectedInputUnit == 'Pied' && selectedOutputUnit == 'Mètre') {
    outputValue = inputValue / 3.28084;
    } else if (selectedInputUnit == 'Mètre' && selectedOutputUnit == 'Pouce') {
    outputValue = inputValue * 39.3701;
    } else if (selectedInputUnit == 'Pouce' && selectedOutputUnit == 'Mètre') {
    outputValue = inputValue / 39.3701;
    }
    setState(() {});
  }
@override
Widget build(BuildContext context) {
return Scaffold(
    appBar: AppBar(
    title: const Text('Convertisseur d\'Unités'),
    ),
    body: Padding(
    padding: const EdgeInsets.all(16.0),
    child: Column(
    mainAxisAlignment:
    MainAxisAlignment.center,
      children: [
      TextField(
      keyboardType:
      TextInputType.number,
      decoration:
      const InputDecoration(labelText: 'Valeur'),
      onChanged: (value) {
      inputValue = double.tryParse(value) ?? 0.0;
      },
      ),
      const SizedBox(height: 20),
      Row(
      mainAxisAlignment:
      MainAxisAlignment.spaceEvenly,
    children: [
      DropdownButton<String>(
      value: selectedInputUnit,
      onChanged: (String? newValue)
      {
      setState(() {
      selectedInputUnit =newValue!;
      });
      },
     items:
     lengthUnits.map<DropdownMenuItem<String>>((String value) {
      return DropdownMenuItem<String>(
      value: value,
      child: Text(value),
      );
      }).toList(),
      ),
    IconButton(
    icon: const Icon(Icons.swap_horiz),
    onPressed: () {
    setState(() {
    var temp = selectedInputUnit;
    selectedInputUnit = selectedOutputUnit;
    selectedOutputUnit = temp;
    });
    },
    ),
    DropdownButton<String>(
    value: selectedOutputUnit,
    onChanged: (String? newValue)
    {
    setState(() {
    selectedOutputUnit = newValue!;
    });
    },
    items:
    lengthUnits.map<DropdownMenuItem<String>>((String value) {
    return DropdownMenuItem<String>(
    value: value,
    child: Text(value),
    );
    }).toList(),
    ),
    ],
    ),
    const SizedBox(height: 20),
    ElevatedButton(
    onPressed: () {
    convert();
    },
    child: const Text('Convertir'),
    ),
    const SizedBox(height: 20),
    Text('Résultat : $outputValue $selectedOutputUnit'),
    ],
    ),
    ),
    );
    }
    }