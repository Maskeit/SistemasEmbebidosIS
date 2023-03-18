<?php
    function head(){
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../resources/css/bootstrap.css">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.10.3/font/bootstrap-icons.css">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Open+Sans&display=swap" rel="stylesheet">
<style>
    body {
        font-family: 'Open Sans', sans-serif;   
        }
</style>
    <title>Blog ejercicio2</title>
</head>
<body>
    <div id="app" class="container-fluid.p-0">
            <header class="row m-0 bg-ligth">
                <div class="col-9">
                    <h1 class="ml-3 mt-2">El Comentario</h1>
                </div>
                <div class="col-3">

                </div>
            </header>
            <nav class="navbar navbar-expand-lg navbar-light bg-light">
                <div class="container-fluid">                    
                    <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
                        <span class="navbar-toggler-icon"></span>
                    </button>
                    <div class="collapse navbar-collapse" id="navbarSupportedContent">
                    <ul class="navbar-nav me-auto mb-2 mb-lg-0">
                        <li class="nav-item">
                            <a class="nav-link " aria-current="page" href="../index.php">Inicio</a>
                        </li>
                        <li class="nav-item">
                            <a class="nav-link" href="#">Seccion 1</a>
                        </li>

                        <li class="nav-item">
                            <a class="nav-link " href="#" tabindex="-1" aria-disabled="true">Seccion 2</a>
                        </li>
                    </ul>

                    <form class="d-flex" role="search">
                        <input class="form-control me-2" id="buscar-palabra" type="search" placeholder="Search" aria-label="Search">
                        <button class="btn btn-outline-success" onclick="app.buscarPalabra()" type="button"><i class="bi bi-search"></i></button>
                    </form>

                    </div>
                </div>
            </nav>
<?php
    }
    function foot(){
?>         
    </div>

    <script src="../resources/js/bootstrap.min.js"></script>
    <script src="../jsApp/jquery.js"></script>
    <script src="../jsApp/app.js"></script>

</body>
</html>
<?php }