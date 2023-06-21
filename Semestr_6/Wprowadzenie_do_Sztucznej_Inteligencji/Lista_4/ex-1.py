import tensorflow as tf
from tensorflow.keras.datasets import mnist
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score

# Wczytanie danych MNIST
(x_train, y_train), (x_test, y_test) = mnist.load_data()

# Przygotowanie danych treningowych
x_train = x_train.reshape(-1, 28 * 28) / 255.0
y_train = y_train.astype('int')

# Przygotowanie danych testowych
x_test = x_test.reshape(-1, 28 * 28) / 255.0
y_test = y_test.astype('int')

# Tworzenie i trening lasu decyzyjnego
rf = RandomForestClassifier(n_estimators=100)
rf.fit(x_train, y_train)

# Przewidywanie etykiet dla danych testowych
y_pred = rf.predict(x_test)

# Obliczanie współczynnika prawidłowej rozpoznawalności
accuracy = accuracy_score(y_test, y_pred)
print("Współczynnik prawidłowej rozpoznawalności: {:.2f}%".format(accuracy * 100))
