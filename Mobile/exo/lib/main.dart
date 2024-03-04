import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        primarySwatch: Colors.deepPurple,
      ),
      home: const MyHomePage(title: 'Flutter Demo Home Page'),
      debugShowCheckedModeBanner: false,
    );
  }
}

class MyHomePage extends StatelessWidget {
  const MyHomePage({Key? key, required this.title}) : super(key: key);
  final String title;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.black87,
      body: Padding(
        padding: const EdgeInsets.all(15.0),
        child: Column(
            // mainAxisAlignment: MainAxisAlignment.center,
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Padding(
                  padding: EdgeInsets.only(top: 90),
                  child: Column(children: [
                    Text(
                      "Nice to\nmeet you,\nwe will\nchat soon. ",
                      style: TextStyle(
                        fontSize: 40,
                        color: Colors.white,
                      ),
                      textAlign: TextAlign.left,
                    ),
                    // SizedBox(height: 20),
                    ElevatedButton(
                      onPressed: () {
                        Navigator.push(
                          context,
                          MaterialPageRoute(
                              builder: (context) =>
                                  const MyHome(title: 'Page d\'accueil')),
                        );
                      },
                      child: const Text(
                        "Page d\'accueil",
                        style: TextStyle(
                          color: Colors.white,
                        ),
                      ),
                      style: ElevatedButton.styleFrom(
                        backgroundColor: const Color.fromRGBO(44, 234, 224, 1),
                        shape: RoundedRectangleBorder(
                            borderRadius: BorderRadius.zero),
                      ),
                    ),
                  ]))
            ]),
      ),
    );
  }
}

class MyHome extends StatelessWidget {
  const MyHome({Key? key, required this.title}) : super(key: key);
  final String title;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(title),
      ),
      body: Padding(
        padding: const EdgeInsets.all(15.0),
        child: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            crossAxisAlignment: CrossAxisAlignment.center,
            children: <Widget>[
              Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: const [
                  Text(
                    "Hello",
                    style: TextStyle(fontSize: 80),
                  ),
                  Text(
                    ".",
                    style: TextStyle(
                      color: Color.fromRGBO(44, 234, 224, 1),
                      fontSize: 75,
                    ),
                  ),
                ],
              ),
              const SizedBox(height: 10),
              Row(
                mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                children: [
                  Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: const [
                      Text("125 Washington"),
                      Text("azerty"),
                      Text("BP 1206 Street"),
                    ],
                  ),
                  Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: const [
                      Text("Thibach@yahoo.fr"),
                      Text("+647 2147 256"),
                      Text("www.dribbble.com"),
                    ],
                  ),
                ],
              ),
              const SizedBox(height: 10),
              Padding(
                padding: const EdgeInsets.all(8.0),
                child: TextField(
                  decoration: InputDecoration(
                    labelText: 'Name',
                  ),
                  onChanged: (text) {
                    print('Input: $text');
                  },
                ),
              ),
              Padding(
                padding: const EdgeInsets.all(10.0),
                child: TextField(
                  decoration: InputDecoration(
                    labelText: 'Phone',
                  ),
                  onChanged: (text) {
                    print('Input: $text');
                  },
                ),
              ),
              Padding(
                padding: const EdgeInsets.all(10.0),
                child: TextField(
                  decoration: InputDecoration(
                    labelText: 'Email',
                  ),
                  onChanged: (text) {
                    print('Input: $text');
                  },
                ),
              ),
              const SizedBox(height: 20),
              const Text("Anything else you'd like us to know ?"),
              ElevatedButton(
                onPressed: () {
                  // Action lorsque le bouton "Submit" est pressé
                },
                child: const Text("Submit"),
                style: ElevatedButton.styleFrom(
                  backgroundColor: const Color.fromRGBO(44, 234, 224, 1),
                  shape:
                      RoundedRectangleBorder(borderRadius: BorderRadius.zero),
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}


class Login extends StatelessWidget {
  const Login({Key? key, required this.title}) : super(key: key);
  final String title;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(title),
      ),
      body: Padding(
        padding: const EdgeInsets.all(15.0),
        child: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            crossAxisAlignment: CrossAxisAlignment.center,
            children: <Widget>[
              Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: const [
                  Image.asset('assets/images/1.jpg'),
              const SizedBox(height: 10),
              Padding(
                padding: const EdgeInsets.all(8.0),
                child: TextField(
                  decoration: InputDecoration(
                    labelText: 'Name',
                  ),
                  onChanged: (text) {
                    print('Input: $text');
                  },
                ),
              ),
              Padding(
                padding: const EdgeInsets.all(10.0),
                child: TextField(
                  decoration: InputDecoration(
                    labelText: 'Phone',
                  ),
                  onChanged: (text) {
                    print('Input: $text');
                  },
                ),
              ),
              Padding(
                padding: const EdgeInsets.all(10.0),
                child: TextField(
                  decoration: InputDecoration(
                    labelText: 'Email',
                  ),
                  onChanged: (text) {
                    print('Input: $text');
                  },
                ),
              ),
              const SizedBox(height: 20),
              const Text("Anything else you'd like us to know ?"),
              ElevatedButton(
                onPressed: () {
                  // Action lorsque le bouton "Submit" est pressé
                },
                child: const Text("Submit"),
                style: ElevatedButton.styleFrom(
                  backgroundColor: const Color.fromRGBO(44, 234, 224, 1),
                  shape:
                      RoundedRectangleBorder(borderRadius: BorderRadius.zero),
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}
