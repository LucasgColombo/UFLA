<?php
header("Content-Type: text/html; charset=iso-8859-1",true);
?>
<html>
  <head><title>Incluir/Editar um contato.</title></head>
  <body>
    <form name="form1" method="POST" action="incluir.php">
      <?php
      if(isset($_GET["CPF"])){	
        include("./config.php");
        $con = mysqli_connect($host, $login, $senha, $bd);
      ?>
        <center><h3>Editar Contato</h3></center>
      <?php
        $sql = "SELECT * FROM pessoa WHERE CPF=".$_GET['CPF'];
        $result = mysqli_query($con, $sql);
        $vetor = mysqli_fetch_array($result, MYSQLI_ASSOC);
        mysqli_close($con);
      ?>
        <input type="hidden" name="CPF" value="<?php echo $_GET['CPF']; ?>">
      <?php
      }else{
      ?>
        <center><h3>Cadastrar novo usuario</h3></center>
      <?php
      }
      ?>
      
      <table border="0" align="center" width="35%">
      <tr>
          <td width="20%">CPF:</td>
            <td colspan="2" width="90%">
            <input type="text" name="cpf" value="<?php echo @$vetor['cpf']; ?>" maxlength="11" size="31">
          </td>
        </tr>

        <tr>
          <td width="20%">NomeSocial:</td>
            <td colspan="2" width="90%">
            <input type="text" name="nomeSocial" value="<?php echo @$vetor['nomeSocial']; ?>" maxlength="50" size="31">
          </td>
        </tr>

        <tr>
          <td width="20%">Sexo(M/F):</td>
            <td colspan="2" width="90%">
            <input type="text" name="sexo" value="<?php echo @$vetor['sexo']; ?>" maxlength="1" size="3">
          </td>
        </tr>

        <tr>
          <td for="nascimento">Nascimento:</td>
          <td colspan="2" width="90%">
            <input type="date" name="nascimento" name="nascimento" value="<?php echo @$vetor ['nascimento']; ?>" required>
          </td>
        </tr>

        <tr>
          <td width="20%">Estado:</td>
            <td colspan="2" width="90%">
            <input type="text" name="estado" value="<?php echo @$vetor['estado']; ?>" maxlength="2" size="3">
          </td>
        </tr>
        
        <tr>
          <td width="20%">Cidade:</td>
            <td colspan="2" width="90%">
            <input type="text" name="cidade" value="<?php echo @$vetor['cidade']; ?>" maxlength="50" size="31">
          </td>
        </tr>
        
        <tr>
          <td width="20%">Bairro:</td>
            <td colspan="2" width="90%">
            <input type="text" name="bairro" value="<?php echo @$vetor['bairro']; ?>" maxlength="50" size="31">
          </td>
        </tr>

        <tr>
          <td width="20%">Logradouro:</td>
            <td colspan="2" width="90%">
            <input type="text" name="logradouro" value="<?php echo @$vetor['logradouro']; ?>" maxlength="50" size="31">
          </td>
        </tr>

        <tr>
          <td width="20%">Numero:</td>
            <td colspan="2" width="90%">
            <input type="text" name="numero" value="<?php echo @$vetor['numero']; ?>" maxlength="4" size="3">
          </td>
        </tr>

        <tr>
          <td width="20%">Complemento:</td>
            <td colspan="2" width="90%">
            <input type="text" name="complemento" value="<?php echo @$vetor['complemento']; ?>" maxlength="50" size="31">
          </td>
        </tr>
        <tr>
            <td colspan="3" align="center">
              <input type="button" value="Cancelar" onclick="location.href='index.php'">
              <input type="submit" value="Gravar" onclick="location.href='incluir.php'">
            </td>
        </tr>
      </table>
    </form>
  </body>
</html>